/* Keep track of attributes of the shell.  */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_NAME_LEN 256
#define MAX_PATH_LEN 1024
#define TOK_BUFSIZE 100
#define TOK_DELIM " \t\r\n\a"

pid_t shell_pgid;
struct termios shell_tmodes;
int shell_terminal;
int shell_is_interactive;

char* buildin[256] = {"cd", "quit", "exit"};


/* Make sure the shell is running interactively as the foreground job
      before proceeding. */

/* A process is a single process.  */
typedef struct process
{
	struct process *next;       /* next process in pipeline */
	char **argv;                /* for exec */
	pid_t pid;                  /* process ID */
	char completed;             /* true if process has completed */
	char stopped;               /* true if process has stopped */
	int status;                 /* reported status value */
	int f_in;
	int f_out;
	char *fn_in;
	char *fn_out;
} process;
/* A job is a pipeline of processes.  */
typedef struct job
{
	struct job *next;           /* next active job */
	char *command;              /* command line, used for messages */
	process *first_process;     /* list of processes in this job */
	pid_t pgid;                 /* process group ID */
	char notified;              /* true if user told about stopped job */
	struct termios tmodes;      /* saved terminal modes */
	int stdin, stdout, stderr;  /* standard i/o channels */
	char *infile;
	char *outfile;
	int foreground;
} job;

/* The active jobs are linked into a list.  This is its head.   */
job *first_job = NULL;



void wait_for_job (job *j);
void format_job_info (job *j, const char *status);
void update_status (void);

void free_process (process* p)
{
	int i;
	if(!p->argv) return;
	for (i = 0; p->argv[i] && i < 256; ++i)
	{
		free(p->argv[i]);
	}
	free(p->argv);
}

void free_job (job *j)
{
	if(!j) return;
	process* p = j->first_process;
	while(p)
	{
		process* tmp = p->next;
		free_process(p);
		p = tmp;
	}
	free(j->infile);
	free(j->outfile);
}

void
print_prompt (void)
{
	printf("%s 0$ ", getcwd(NULL,NULL));
}

/* Find the active job with the indicated pgid.  */
job *
find_job (pid_t pgid)
{
	job *j;

	for (j = first_job; j; j = j->next)
		if (j->pgid == pgid)
			return j;
	return NULL;
}

/* Return true if all processes in the job have stopped or completed.  */
int
job_is_stopped (job *j)
{
	process *p;

	for (p = j->first_process; p; p = p->next)
		if (!p->completed && !p->stopped)
			return 0;
	return 1;
}

/* Return true if all processes in the job have completed.  */
int
job_is_completed (job *j)
{
	process *p;

	for (p = j->first_process; p; p = p->next)
		if (!p->completed)
			return 0;
	return 1;
}

void
init_shell ()
{
	/* See if we are running interactively.  */
	shell_terminal = STDIN_FILENO;
	shell_is_interactive = isatty (shell_terminal);

	if (shell_is_interactive)
	{
		/* Loop until we are in the foreground.  */
		while (tcgetpgrp (shell_terminal) != (shell_pgid = getpgrp ()))
			kill (- shell_pgid, SIGTTIN);

		/* Ignore interactive and job-control signals.  */
		signal (SIGINT, SIG_IGN);
		signal (SIGQUIT, SIG_IGN);
		signal (SIGTSTP, SIG_IGN);
		signal (SIGTTIN, SIG_IGN);
		signal (SIGTTOU, SIG_IGN);
		signal (SIGCHLD, SIG_IGN);

		/* Put ourselves in our own process group.  */
		shell_pgid = getpid ();
		if (setpgid (shell_pgid, shell_pgid) < 0)
		{
			perror ("Couldn't put the shell in its own process group");
			exit (1);
		}

		/* Grab control of the terminal.  */
		tcsetpgrp (shell_terminal, shell_pgid);
		
		/* Save default terminal attributes for shell.  */
		tcgetattr (shell_terminal, &shell_tmodes);
	}
}

/* Put job j in the foreground.  If cont is nonzero,
   restore the saved terminal modes and send the process group a
   SIGCONT signal to wake it up before we block.  */

void
put_job_in_foreground (job *j, int cont)
{
	j->foreground = 1;
	/* Put the job into the foreground.  */
	tcsetpgrp (shell_terminal, j->pgid);
	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (shell_terminal, TCSADRAIN, &j->tmodes);
		if (kill (- j->pgid, SIGCONT) < 0)
			perror ("kill (SIGCONT)");
	}
	/* Wait for it to report.  */
	wait_for_job (j);

	/* Put the shell back in the foreground.  */
	tcsetpgrp (shell_terminal, shell_pgid);

	/* Restore the shell’s terminal modes.  */
	tcgetattr (shell_terminal, &j->tmodes);
	tcsetattr (shell_terminal, TCSADRAIN, &shell_tmodes);
}

/* Put a job in the background.  If the cont argument is true, send
      the process group a SIGCONT signal to wake it up.  */

void
put_job_in_background (job *j, int cont)
{
	j->foreground = 0;
	/* Send the job a continue signal, if necessary.  */
	if (cont)
		if (kill (-j->pgid, SIGCONT) < 0)
			perror ("kill (SIGCONT)");
}

void
launch_process (process *p, pid_t pgid,
				int infile, int outfile, int errfile,
				int foreground)
{
	pid_t pid;

	if (shell_is_interactive)
	{
		/* Put the process into the process group and give the process group
		   the terminal, if appropriate.
		This has to be done both by the shell and in the individual
		child processes because of potential race conditions.  */
		pid = getpid ();
		if (pgid == 0) pgid = pid;
		setpgid (pid, pgid);
		if (foreground)
			tcsetpgrp (shell_terminal, pgid);

		/* Set the handling for job control signals back to the default.  */
		signal (SIGINT, SIG_DFL);
		signal (SIGQUIT, SIG_DFL);
		signal (SIGTSTP, SIG_DFL);
		signal (SIGTTIN, SIG_DFL);
		signal (SIGTTOU, SIG_DFL);
		signal (SIGCHLD, SIG_DFL);
	}

	/* Set the standard input/output channels of the new process.  */
	if (infile != STDIN_FILENO)
	{
		dup2 (infile, STDIN_FILENO);
		close (infile);
	}
	if (outfile != STDOUT_FILENO)
	{
		dup2 (outfile, STDOUT_FILENO);
		close (outfile);
	}
	if (errfile != STDERR_FILENO)
	{
		dup2 (errfile, STDERR_FILENO);
		close (errfile);
	}

	/* Exec the new process.  Make sure we exit.  */
	execvp (p->argv[0], p->argv);
	perror ("execvp");
	exit (1);
}

void lauch_buildin (process *p, int infile, int outfile, int errfile)
{
	/* Set the standard input/output channels of the new process.  */
	if (strcmp (p->argv[0], "cd") == 0)
	{
		char *cd_path = NULL;
		if(!p->argv[1])
			cd_path = strdup(getenv("HOME"));
		else if (p->argv[1][0] == '~')
		{
			cd_path = (char*)malloc(strlen(getenv("HOME")) + strlen (p->argv[1]));
			strcpy (cd_path, getenv("HOME"));
			strncpy (cd_path + strlen(getenv("HOME")), p->argv[1] + 1, strlen(p->argv[1]));
		}
		else 
			cd_path = strdup(p->argv[1]); 
		if (chdir(cd_path) < 0)
			perror("cd:");

		free(cd_path);
	}
	else if (strcmp(p->argv[0], "exit") == 0 || strcmp(p->argv[0], "quit")==0)
	{
		update_status();
		exit(0);
	}
}

int is_buildin (process *p)
{
	int i;
	for (i = 0; buildin[i]; ++i)
		if(strcmp(buildin[i], p->argv[0]) == 0)
			return 1;
	return 0;
}

void
launch_job (job *j, int foreground)
{
	process *p;
	pid_t pid;
	int mypipe[2], infile, outfile;


	if (j->infile)
	{
		j->stdin = open(j->infile, O_RDONLY);
		if (j->stdin < 0)
		{
			perror(j->infile);
			exit(1);
		}
	}
	if (j->outfile)
	{
		j->stdout = open(j->outfile, O_WRONLY|O_CREAT|O_TRUNC, 0666);
		if (j->stdout < 0)
		{
			perror(j->outfile);
			exit(1);
		}
	}

	infile = j->stdin;
	for (p = j->first_process; p; p = p->next)
	{
		/* Set up pipes, if necessary.  */
		if (p->next)
		{
			if (pipe (mypipe) < 0)
			{
				perror ("pipe");
				exit (1);
			}
			outfile = mypipe[1];
		}
		else
			outfile = j->stdout;

		if(is_buildin(p)){
			lauch_buildin(p, infile, outfile, j->stderr);
			p->completed = 1;
		}
		else{
			/* Fork the child processes.  */
			pid = fork ();
			if (pid == 0)
				/* This is the child process.  */
				launch_process (p, j->pgid, infile,
						outfile, j->stderr, foreground);
			else if (pid < 0)
			{
				/* The fork failed.  */
				perror ("fork");
				exit (1);
			}
			else
			{
				/* This is the parent process.  */
				p->pid = pid;
				if (shell_is_interactive)
				{
					if (!j->pgid)
						j->pgid = pid;
					setpgid (pid, j->pgid);
				}
			}
		}

		/* Clean up after pipes.  */
		if (infile != j->stdin)
			close (infile);
		if (outfile != j->stdout)
			close (outfile);
		infile = mypipe[0];
	}

//	format_job_info (j, "launched");

	if (!shell_is_interactive)
		wait_for_job (j);
	else if (foreground)
		put_job_in_foreground (j, 0);
	else{
		put_job_in_background (j, 0);
		format_job_info (j, "backgroud");
	}
}

/* Store the status of the process pid that was returned by waitpid.
   Return 0 if all went well, nonzero otherwise.  */

int
mark_process_status (pid_t pid, int status)
{
	job *j;
	process *p;
	if (pid > 0)
	{
		/* Update the record for the process.  */
		for (j = first_job; j; j = j->next)
			for (p = j->first_process; p; p = p->next)
				if (p->pid == pid)
				{
					p->status = status;
					if (WIFSTOPPED (status))
						p->stopped = 1;
					else
					{
						p->completed = 1;
						if (WIFSIGNALED (status))
							fprintf (stderr, "%d: Terminated by signal %d.\n",
									(int) pid, WTERMSIG (p->status));
					}
					return 0;
				}
		fprintf (stderr, "No child process %d.\n", pid);
		return -1;
	}
	else if (pid == 0 || errno == ECHILD)
		/* No processes ready to report.  */
		return -1;
	else {
		/* Other weird errors.  */
		perror ("waitpid");
		return -1;
	}
}
/* Check for processes that have status information available,
   without blocking.  */

void
update_status (void)
{
	int status;
	pid_t pid;

	do
		pid = waitpid (WAIT_ANY, &status, WUNTRACED|WNOHANG);
	while (!mark_process_status (pid, status));
}
/* Check for processes that have status information available,
   blocking until all processes in the given job have reported.  */

void
wait_for_job (job *j)
{
	int status;
	pid_t pid;

	do
		pid = waitpid (WAIT_ANY, &status, WUNTRACED);
	while (!mark_process_status (pid, status)
			&& !job_is_stopped (j)
			&& !job_is_completed (j));
}
/* Format information about job status for the user to look at.  */

void
format_job_info (job *j, const char *status)
{
	fprintf (stderr, "%ld (%s): %s\n", (long)j->pgid, status, j->command);
}
/* Notify the user about stopped or terminated jobs.
   Delete terminated jobs from the active job list.  */

void
do_job_notification (void)
{
	job *j, *jlast, *jnext;
	process *p;

	/* Update status information for child processes.  */
	update_status ();

	jlast = NULL;
	for (j = first_job; j; j = jnext)
	{
		jnext = j->next;

		/* If all processes have completed, tell the user the job has
		   completed and delete it from the list of active jobs.  */
		if (job_is_completed (j)) {
//			format_job_info (j, "completed");
			if (jlast)
				jlast->next = jnext;
			else
				first_job = jnext;
//			free_job (j);
		}

		/* Notify the user about stopped jobs,
		   marking them so that we won’t do this more than once.  */
		else if (job_is_stopped (j) && !j->notified) {
			format_job_info (j, "stopped");
			j->notified = 1;
			jlast = j;
		}

		/* Don’t say anything about jobs that are still running.  */
		else
			jlast = j;
	}
}

/* Mark a stopped job J as being running again.  */

void
mark_job_as_running (job *j)
{
	process *p;

	for (p = j->first_process; p; p = p->next)
		p->stopped = 0;
	j->notified = 0;
}
/* Continue the job J.  */

void
continue_job (job *j, int foreground)
{
	mark_job_as_running (j);
	if (foreground)
		put_job_in_foreground (j, 1);
	else
		put_job_in_background (j, 1);
}

job* create_job ()
{
	job* j = (job*)malloc(sizeof(job));
	if (!j)
	{
		perror ("malloc");
		return NULL;
	}
	j->first_process = NULL;
//	j->valid = 1;
//	j->id = 0;
	j->infile = NULL;
	j->outfile = NULL;
	j->stdin = STDIN_FILENO;
	j->stdout = STDOUT_FILENO;
	j->stderr = STDERR_FILENO;
	j->foreground = 1;
	j->notified = 0;
	j->pgid = 0;
	return j;
}

char *read_line(){
	char *line = NULL;
	size_t bufsize = 0; // have getline allocate a buffer for us
	getline(&line, &bufsize, stdin);
	return line;
}

void split_line(char *line, job *j)
{
	int bufsize = TOK_BUFSIZE, position = 0;
	int i,k;
	char **tokens = (char**)malloc(bufsize * sizeof(char*));
	char *token,*saveptr;

	if (!tokens) {
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(line, TOK_DELIM,&saveptr);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
			bufsize += TOK_BUFSIZE;
			tokens = (char**)realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok_r(NULL, TOK_DELIM,&saveptr);
	}
	tokens[position] = NULL;
	
	process* p = (process*)malloc(sizeof(process));
	if (!p)
	{
		perror ("p_malloc");
		exit(1);
	}
	p->pid = 0;
	p->next = NULL;
	p->completed = 0;
	p->stopped = 0;
	p->argv = (char**)malloc(bufsize * sizeof(char*));
	p->f_in = 0;
	p->f_out = 0;

	j->first_process = p;

	k=0;

	do{
		for(i=0;tokens[k] && k<position && strcmp(tokens[k],"|")!=0;++i){
			if(strcmp(tokens[k],"<")==0){
				p->f_in = 1;
				++k;
				p->fn_in = (char*)malloc(sizeof(tokens[k])*sizeof(char));
				sprintf(p->fn_in,"%s",tokens[k++]);
				j->infile = (char*)malloc(sizeof(tokens[k])*sizeof(char));
				sprintf(j->infile,"%s",tokens[k-1]);
				--i;
			}
			else if(strcmp(tokens[k],">")==0){
				p->f_out = 1;
				++k;
				p->fn_out = (char*)malloc(sizeof(tokens[k])*sizeof(char));
				sprintf(p->fn_out,"%s",tokens[k++]);
				j->outfile = (char*)malloc(sizeof(tokens[k])*sizeof(char));
				sprintf(j->outfile,"%s",tokens[k-1]);
				--i;
			}
			else
				p->argv[i] = tokens[k++];
		}
		p->argv[i] = NULL;
		if(k==position && tokens[k]==NULL) break;
		++k;

		process* p2 = (process*)malloc(sizeof(process));
		if (!p2)
		{
	   		perror ("p_malloc");
			exit(1);
   		}
		p2->pid = 0;
   		p2->next = NULL;
   		p2->completed = 0;
   		p2->stopped = 0;
   		p2->argv = (char**)malloc(bufsize * sizeof(char*));
		p->f_in = 0;
		p->f_out = 0;

		p->next = p2;
		p = p2;

	}while(1);
}

int main(){
	init_shell();

	int flag=1;
	char *input_buf;
	do{
		print_prompt();
		job *j = create_job();
		input_buf = read_line();
		split_line(input_buf,j);
		if(first_job){
			job *t;
			for(t = first_job; t->next; t = t->next);
			t->next = j;
		}
		else
			first_job = j;
		launch_job(j, j->foreground);
		do_job_notification();
	}while(flag);

	return 0;
}




