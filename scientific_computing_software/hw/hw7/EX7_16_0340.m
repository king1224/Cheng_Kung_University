hd=@EX7_16_0340fun;
tspan=[1 10];
y0=0;
[t y]= ode45(hd,tspan,y0);

plot(t,y);
xlabel('t');
ylabel('V(out)');
title('電壓對時間作圖');