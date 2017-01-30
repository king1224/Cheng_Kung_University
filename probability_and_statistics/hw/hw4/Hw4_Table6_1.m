clear all;
r=0:10;
p=[0.05 0.1 0.5 0.05 0.05 0.05];
n=[10 10 10 20 50 100];
for i = 1 : 6
    u=n(i)*p(i);
    s=sqrt(u*(1-p(i)));
    tmp=0;
    yb=binopdf(r,n(i),p(i));
    yn=normpdf(r,u,s);
    %normal distribution场だ揭セ盢r璽计常r=0
    %珿ノtmpрnormalだガr=0~50癬ㄓノ1Ι碞琌璽计场だ
    for j=1:11
        tmp=tmp+yn(j);
    end
    for j=11:50
        tmp=tmp+normpdf(j,u,s);
    end
    yn(1)=yn(1)+1-tmp;
    subplot(2,3,i);
    hold on;
    title(['p=',num2str(p(i)),'  n=',num2str(n(i))]);
    xlabel('r');
    ylabel('probability');
    plot(r,yb,'r');
    plot(r,yn);
    plot(r,yb-yn,'black');
    axis([0,10,-0.2,0.6]);
    grid on;
end