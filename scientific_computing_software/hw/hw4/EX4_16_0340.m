n=input('Enter the number of input [x y] points：');%先輸入共有多少點
for ii=1:n;%每個點全部讀取，存起來
    temp=input('Enter [x y] pair：');
    x(ii)=temp(1); y(ii)=temp(2);
end
c=polyfit(x,y,1);
plot(x,y,'bo');%畫出各點
hold on;
xbar=mean(x);%x算數平均
ybar=mean(y);%y算數平均
yint=ybar-c(1)*xbar;
xmin=min(x); xmax=max(x);%x的最大最小
ymin=c(1)*xmin+yint;%最小平方法直線後對應x的y
ymax=c(1)*xmax+yint;
plot([xmin xmax],[ymin ymax],'r-','linewidth',2);
hold off;
%加註解
title('\bfLeast-Squares Fit');
xlabel('\bf\itx');
ylabel('\bf\ity');
legend('Input data','Fitted line');
grid on;