t=0:0.1:10;     %0<=t<=10
a=exp(-0.2*t);
w=188.5*(1-a);  %轉速
u=10*a;         %力矩
figure(1)       %分為四個子圖畫
subplot(2,2,1)
y=u;
plot(x,y); xlabel('t'); ylabel('\tau_{IND}');       %力矩對時間的關係
title('\tau_{IND} with t');
subplot(2,2,2)
y=w;
plot(x,y); xlabel('t'); ylabel('\omega_{m}');       %轉速對時間的關係
title('\omega_{m} with t');
subplot(2,2,3)
y=w.*u;
plot(x,y); xlabel('t'); ylabel('power');            %功率對時間的關係
title('power with t');
subplot(2,2,4)
semilogy(x,y); xlabel('t'); ylabel('power');        %功率對時間的關係，用對數刻度
title('power with t(對數刻度)');