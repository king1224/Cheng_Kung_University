#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>

MODULE_LICENSE("Dual BSD/GPL");

static int mask = 111;
static char *name1="swap_string",*name2="calc",*name3="sum_tree";

module_param(mask,int,S_IRUGO | S_IWUSR);
module_param(name1,charp,S_IRUGO | S_IWUSR);
module_param(name2,charp,S_IRUGO | S_IWUSR);
module_param(name3,charp,S_IRUGO | S_IWUSR);




static int i,k;

static char swap_string[100],tmp[100];
static int swap_string_position,retval;

static int calc,tmp_calc,calc_input_position1,calc_input_position2,calc_input[100];
static bool Is_prev_num,minus_flag,Is_input_num[100];

static struct Node{
	int value;
	int next_start;
	int next_end;
}sum_tree_input[10][10];

static int sum_tree_num[100],sum_tree_position[10],sum_tree_deep_count,tmp_sum_tree,sum_tree_num_position,ans_position;
static char sum_tree[300];

static ssize_t swap_string_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf)
{
	return sprintf(buf,"%s\n",swap_string);
}

static ssize_t swap_string_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count)
{
	sscanf(buf,"%d %s",&swap_string_position,swap_string);

	for(i=0;i<strlen(swap_string);++i)
		tmp[i]=swap_string[i];
	for(i=swap_string_position;i<strlen(tmp);++i)
		swap_string[i-swap_string_position]=tmp[i];
	for(i=0;i<swap_string_position;++i)
		swap_string[strlen(tmp)-swap_string_position+i]=tmp[i];

	return count;
}

static ssize_t calc_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf)
{
	return sprintf(buf,"%d\n",calc);
}

static ssize_t calc_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count)
{
	calc=tmp_calc=calc_input_position1=calc_input_position2=0;
	Is_prev_num=minus_flag=false;
	for(i=0;i<=strlen(buf);++i){
		if(buf[i]>='0'&&buf[i]<='9'){
			if(Is_prev_num)
				tmp_calc=tmp_calc*10+buf[i]-'0';
			else{
				Is_prev_num=true;
				tmp_calc=buf[i]-'0';
			}
		}
		else if(buf[i]=='%' || buf[i]=='*' || buf[i]=='/' || buf[i]=='+' || buf[i]=='-'){
			if(tmp_calc){
				if(minus_flag){
					tmp_calc=-tmp_calc;
					minus_flag=false;
				}
				calc_input[calc_input_position1]=tmp_calc;
				tmp_calc=0;
				Is_input_num[calc_input_position1++]=true;
			}
			
			if(buf[i+1]>='0' && buf[i+1]<='9'){
				minus_flag=true;
				Is_prev_num=false;
			}
			else{
				Is_prev_num=false;
				calc_input[calc_input_position1]=buf[i];
				Is_input_num[calc_input_position1++]=false;
			}
		}
		else if(tmp_calc){
			if(minus_flag){
				tmp_calc=-tmp_calc;
				minus_flag=false;
			}
			calc_input[calc_input_position1]=tmp_calc;
			tmp_calc=0;
			Is_input_num[calc_input_position1++]=true;
			Is_prev_num=false;
		}
	}

	for(i=0;i<calc_input_position1;++i){
		if(!Is_input_num[i]){
			if(calc_input[i]=='*'){
				calc_input[calc_input_position2]=calc_input[i-1]*calc_input[i+1];
				calc_input[i+1]=calc_input[calc_input_position2];
				Is_input_num[calc_input_position2]=true;
			}
			else if(calc_input[i]=='/'){
				calc_input[calc_input_position2]=calc_input[i-1]/calc_input[i+1];
				calc_input[i+1]=calc_input[calc_input_position2];
				Is_input_num[calc_input_position2]=true;
			}
			else if(calc_input[i]=='%'){
				calc_input[calc_input_position2]=calc_input[i-1]%calc_input[i+1];
				calc_input[i+1]=calc_input[calc_input_position2];
				Is_input_num[calc_input_position2]=true;
			}
			else{
				calc_input[calc_input_position2]=calc_input[i-1];
				Is_input_num[calc_input_position2++]=true;
				calc_input[calc_input_position2]=calc_input[i];
				Is_input_num[calc_input_position2++]=false;
			}
		}
	}
	calc_input[calc_input_position2]=calc_input[i-1];
	Is_input_num[calc_input_position2++]=true;

	calc_input_position1=calc_input_position2;
	calc_input_position2=0;
	
	for(i=0;i<calc_input_position1;++i){
		if(!Is_input_num[i]){
			if(calc_input[i]=='+'){
				calc_input[calc_input_position2]=calc_input[i-1]+calc_input[i+1];
				calc_input[i+1]=calc_input[calc_input_position2];
				Is_input_num[calc_input_position2]=true;
			}
			else if(calc_input[i]=='-'){
				calc_input[calc_input_position2]=calc_input[i-1]-calc_input[i+1];
				calc_input[i+1]=calc_input[calc_input_position2];
				Is_input_num[calc_input_position2]=true;
			}
		}
	}
	if(calc_input_position2==0){
		calc=calc_input[0];
	}
	else calc=-9999999;

	return count;
}


static void DFS(int deep,int position)
{
	int j;

	if(sum_tree_input[deep][position].next_start == -1 && sum_tree_input[deep][position].next_end==-1){
		sum_tree_num[sum_tree_num_position++]=sum_tree_input[deep][position].value;
	}
	else{
		for(j=sum_tree_input[deep][position].next_start;j<=sum_tree_input[deep][position].next_end;++j){
			sum_tree_input[deep+1][j].value += sum_tree_input[deep][position].value;
			DFS(deep+1,j);
		}
	}
}


static ssize_t sum_tree_show(struct kobject *kobj,struct kobj_attribute *attr,char *buf)
{
	return sprintf(buf,"%s\n",sum_tree);
}

static ssize_t sum_tree_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf,size_t count)
{
	sum_tree_deep_count=sum_tree_num_position=ans_position=tmp_sum_tree=0;
	sum_tree_input[0][0].value=0;
	sum_tree_position[0]=1;
	for(i=1;i<10;++i)	sum_tree_position[i]=0;
	Is_prev_num=false;
	for(i=0;i<strlen(buf);++i){
		if(buf[i]=='('){
			if(Is_prev_num){
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].value=tmp_sum_tree;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_start=-1;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_end=-1;
				tmp_sum_tree=0;
				++sum_tree_position[sum_tree_deep_count];
				Is_prev_num=false;
			}
			sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]-1].next_start=sum_tree_position[sum_tree_deep_count+1];
			++sum_tree_deep_count;
		}
		else if(buf[i]==')'){
			if(Is_prev_num){
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].value=tmp_sum_tree;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_start=-1;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_end=-1;
				tmp_sum_tree=0;
				++sum_tree_position[sum_tree_deep_count];
				Is_prev_num=false;
			}
			sum_tree_input[sum_tree_deep_count-1][sum_tree_position[sum_tree_deep_count-1]-1].next_end=sum_tree_position[sum_tree_deep_count]-1;
			
			--sum_tree_deep_count;
		}
		else if(buf[i]==' '){
			if(Is_prev_num){
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].value=tmp_sum_tree;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_start=-1;
				sum_tree_input[sum_tree_deep_count][sum_tree_position[sum_tree_deep_count]].next_end=-1;
				tmp_sum_tree=0;
				++sum_tree_position[sum_tree_deep_count];
				Is_prev_num=false;
			}
		}
		else if(buf[i]>='0' && buf[i]<='9'){
			if(Is_prev_num){
				tmp_sum_tree=tmp_sum_tree*10+buf[i]-'0';
			}
			else{
				tmp_sum_tree=buf[i]-'0';
				Is_prev_num=true;
			}
		}
	}

	DFS(0,0);

	for(i=0;i<sum_tree_num_position;++i){
		tmp_sum_tree=0;
		if(i){
			sum_tree[ans_position++]=',';
			sum_tree[ans_position++]=' ';
		}
		while(sum_tree_num[i]){
			for(k=tmp_sum_tree;k>0;--k){
				sum_tree[ans_position+k]=sum_tree[ans_position+k-1];
			}
			sum_tree[ans_position]=sum_tree_num[i]%10 + '0';
			sum_tree_num[i]=sum_tree_num[i]/10;
			++tmp_sum_tree;
		}
		ans_position=ans_position+tmp_sum_tree;
	}

	sum_tree[ans_position]='\0';

	return count;
}


static struct kobj_attribute swap_string_attribute = __ATTR(swap_string,S_IRUGO | S_IWUSR,swap_string_show,swap_string_store);

static struct kobj_attribute calc_attribute = __ATTR(calc,S_IRUGO | S_IWUSR,calc_show,calc_store);

static struct kobj_attribute sum_tree_attribute = __ATTR(sum_tree,S_IRUGO | S_IWUSR,sum_tree_show,sum_tree_store);



static struct attribute *attrs[] = {
	&swap_string_attribute.attr,
	&calc_attribute.attr,
	&sum_tree_attribute.attr,
	NULL,
};
static struct attribute_group attr_group = {
	.attrs = attrs,
};

static struct kobject *hw1_kobj;

static int __init create_hw1(void)
{
	printk(KERN_ALERT "Hello!\n");

	hw1_kobj = kobject_create_and_add("hw1",kernel_kobj);

	swap_string_attribute.attr.name = name1;
	calc_attribute.attr.name = name2;
	sum_tree_attribute.attr.name = name3;

	if(!hw1_kobj)
		return -ENOMEM;
	retval = sysfs_create_group(hw1_kobj,&attr_group);

	if(mask/10/10 == 0)
		sysfs_remove_file(hw1_kobj,&swap_string_attribute.attr);
	if(mask!=8 && mask!=9 && mask!=110 && mask!=111)
		sysfs_remove_file(hw1_kobj,&calc_attribute.attr);
	if(mask%10 != 1 && mask!=9)
		sysfs_remove_file(hw1_kobj,&sum_tree_attribute.attr);

	if(retval)
		kobject_put(hw1_kobj);

	return retval;
}

static void __exit cleanup_hw1(void)
{
	kobject_del(hw1_kobj);
	kobject_put(hw1_kobj);
	printk(KERN_ALERT "Goodbye!\n");
}

module_init(create_hw1);
module_exit(cleanup_hw1);

