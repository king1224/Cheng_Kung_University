%��J�y����l����
ho=input('�п�J�y����l����(m)�G');
%��J�y����t
Vo=input('�п�J�y�������t��(m/s)�G');
%�]�w���O�[�t��
g=-9.81;
%�]�w0~100��
t=0:0.1:100;
%��Ӫ���
h=1/2*g*t.^2+Vo*t+ho;
%��Ӫ��t��
v=g*t+Vo;
%�e�X���B�t�סA�ܦ�ϧO
plot(t,h,'b',t,v,'r');
%�����u���N��
legend('high','speed');
%��Ь�t
xlabel('t');
%�Ϫ�����
title('The high and the speed of a ball fall down.');
%�}��l�I�A��K��
grid on;