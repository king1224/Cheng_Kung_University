use LWP::Simple;
use utf8;
binmode(STDIN,'encoding(utf8)');
binmode(STDOUT,'encoding(utf8)');
binmode(STDERR,'encoding(utf8)');
use strict;
print "台南國賓影城：\n\n";
my $inp1 = get 'http://www.atmovies.com.tw/showtime/theater_t06608_a06.html';
my @tmp1=split('<a href="/movie/',$inp1);
my @end1=split('更新時間:',$tmp1[$#tmp1]);

$tmp1[$#tmp1]=$end1[0];

for(my $i=1;$i<=$#tmp1;$i++)
{
	my ($movie1) = $tmp1[$i] =~ /([\x{4e00}-\x{9fff}][\x{4e00}-\x{9fff}：:\d]+)/u;
	print "$movie1\n";
	
	while(	my ($time1) = $tmp1[$i] =~ /([012]\d[:：]\d\d)/ ){
		print "$time1\n";
		my @ccc1 = split(/[012]\d[:：]\d\d/,$tmp1[$i],2);
		$tmp1[$i]=$ccc1[1];
	}
}

print "\n\n\n台南新光影城：\n\n";
my $inp2 = get 'http://www.atmovies.com.tw/showtime/theater_t06607_a06.html';
my @tmp2=split('<a href="/movie/',$inp2);
my @end2=split('更新時間:',$tmp2[$#tmp2]);
$tmp2[$#tmp2]=$end2[0];
for(my $i=1;$i<=$#tmp2;$i++)
{
	my ($movie2) = $tmp2[$i] =~ /([\x{4e00}-\x{9fff}][\x{4e00}-\x{9fff}：:\d]+)/u;
	print "$movie2\n";
	while(	my ($time2) = $tmp2[$i] =~ /([012]\d[:：]\d\d)/ ){
		print "$time2\n";
		my @ccc2 = split(/[012]\d[:：]\d\d/,$tmp2[$i],2);
		$tmp2[$i]=$ccc2[1];
	}
}



print "\n\n\n台南大遠百威秀影城：\n\n";
my $inp = get 'http://www.atmovies.com.tw/showtime/theater_t06609_a06.html';
my @tmp=split('<a href="/movie/',$inp);
my @end=split('更新時間:',$tmp[$#tmp]);
$tmp[$#tmp]=$end[0];
for(my $i=1;$i<=$#tmp;$i++)
{
	my ($movie) = $tmp[$i] =~ /([\x{4e00}-\x{9fff}][\x{4e00}-\x{9fff}：:\d]+)/u;
	print "$movie\n";
	while(	my ($time) = $tmp[$i] =~ /([012]\d[:：]\d\d)/ ){
		print "$time\n";
		my @ccc = split(/[012]\d[:：]\d\d/,$tmp[$i],2);
		$tmp[$i]=$ccc[1];
	}
}

exit 0;
