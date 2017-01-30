%輸入球的初始高度
ho=input('請輸入球的初始高度(m)：');
%輸入球的初速
Vo=input('請輸入球的釋放初速度(m/s)：');
%設定重力加速度
g=-9.81;
%設定0~100秒
t=0:0.1:100;
%後來的高
h=1/2*g*t.^2+Vo*t+ho;
%後來的速度
v=g*t+Vo;
%畫出高、速度，變色區別
plot(t,h,'b',t,v,'r');
%解釋線條代表
legend('high','speed');
%橫坐標為t
xlabel('t');
%圖的說明
title('The high and the speed of a ball fall down.');
%開格子點，方便看
grid on;