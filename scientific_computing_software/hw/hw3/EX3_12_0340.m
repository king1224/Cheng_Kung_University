%本程式將x軸當成介質交界面，原點當作入射點
theta1=input('請輸入入射角theta1：');%輸入入射角
n1=input('請輸入折射率n1：');%輸入介質1折射率
n2=input('請輸入折射率n2：');%輸入介質2折射率
x=0:0.1:5;
temp=n1/n2*sin(theta1);
if(abs(temp)>1)%如果是全反射
    y1=tan(pi/2-theta1)*x;%利用斜率等於tan(theta)列方程式
    y2=tan(pi/2+theta1)*-x;
    plot(-x,y2);
    hold on;
    plot(x,y1,'r');
    legend('入射線','反射線');
else%如果有折射
    theta2=asin(temp);
    y1=tan(3/2*pi+theta2)*x;
    y2=tan(pi/2+theta1)*-x;
    plot(-x,y2);
    hold on;
    plot(x,y1,'r');
    legend('入射線','反射線');
end
x2=0;
y2=-10:0.1:10;
plot(x2,y2,'k--');%畫出y軸
x3=-10:0.01:10;
y3=0;
plot(x3,y3,'k-');%畫出x軸
hold off;
axis ([-10 10 -10 10]);%只顯示x,y軸顯示到的範圍
title('\bf入射角\theta_{1}在不同介質下與反射角\theta_{2}的關係');
fprintf('反射角=%3.5f\n',theta2);