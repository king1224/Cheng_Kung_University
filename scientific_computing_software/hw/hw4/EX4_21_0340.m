lc=8;%�l÷��
lp=8;%��l��
w=200*0.45359*9.8;%����(���筫)

d=1:7;%�Z��d
temp=sqrt(lp^2 - d.^2);%���x�s�ڸ�����

T=w*lc*lp./d./temp;%�i�OT������
plot(d,T);%�e�X��
%�[�@�ǵ���
title('�l÷�i�O��Z������ƹ�');
xlabel('�Z��d');
ylabel('�i�OT');
grid on;