t=0:0.1:10;     %0<=t<=10
a=exp(-0.2*t);
w=188.5*(1-a);  %��t
u=10*a;         %�O�x
figure(1)       %�����|�Ӥl�ϵe
subplot(2,2,1)
y=u;
plot(x,y); xlabel('t'); ylabel('\tau_{IND}');       %�O�x��ɶ������Y
title('\tau_{IND} with t');
subplot(2,2,2)
y=w;
plot(x,y); xlabel('t'); ylabel('\omega_{m}');       %��t��ɶ������Y
title('\omega_{m} with t');
subplot(2,2,3)
y=w.*u;
plot(x,y); xlabel('t'); ylabel('power');            %�\�v��ɶ������Y
title('power with t');
subplot(2,2,4)
semilogy(x,y); xlabel('t'); ylabel('power');        %�\�v��ɶ������Y�A�ι�ƨ��
title('power with t(��ƨ��)');