%���{���Nx�b�������ɭ��A���I��@�J�g�I
theta1=input('�п�J�J�g��theta1�G');%��J�J�g��
n1=input('�п�J��g�vn1�G');%��J����1��g�v
n2=input('�п�J��g�vn2�G');%��J����2��g�v
x=0:0.1:5;
temp=n1/n2*sin(theta1);
if(abs(temp)>1)%�p�G�O���Ϯg
    y1=tan(pi/2-theta1)*x;%�Q�αײv����tan(theta)�C��{��
    y2=tan(pi/2+theta1)*-x;
    plot(-x,y2);
    hold on;
    plot(x,y1,'r');
    legend('�J�g�u','�Ϯg�u');
else%�p�G����g
    theta2=asin(temp);
    y1=tan(3/2*pi+theta2)*x;
    y2=tan(pi/2+theta1)*-x;
    plot(-x,y2);
    hold on;
    plot(x,y1,'r');
    legend('�J�g�u','�Ϯg�u');
end
x2=0;
y2=-10:0.1:10;
plot(x2,y2,'k--');%�e�Xy�b
x3=-10:0.01:10;
y3=0;
plot(x3,y3,'k-');%�e�Xx�b
hold off;
axis ([-10 10 -10 10]);%�u���x,y�b��ܨ쪺�d��
title('\bf�J�g��\theta_{1}�b���P����U�P�Ϯg��\theta_{2}�����Y');
fprintf('�Ϯg��=%3.5f\n',theta2);