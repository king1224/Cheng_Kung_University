%設定好一些初始值
q=1.602e-19;
k=1.38e-23;
v=-1.0:0.1:0.6;
i0=2e-6;

%分三個不同溫度 75度F
T=(75-32)*5/9+100;
temp=(q*v)/(k*T);
i=i0*(exp(temp)-1);
plot(v,i);
hold on;
%100度F
T=(100-32)*5/9+100;
temp=(q*v)/(k*T);
i=i0*(exp(temp)-1);
plot(v,i,'r');
%125度F
T=(125-32)*5/9+100;
temp=(q*v)/(k*T);
i=i0*(exp(temp)-1);
plot(v,i,'y');
hold off;
%註解
legend('75(F)','100(F)','125(F)');