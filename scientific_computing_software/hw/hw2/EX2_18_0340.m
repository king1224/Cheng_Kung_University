%設定好L、C、R、Vo
L=0.25*10^-3;
C=0.1*10^-9;
R=50;
Vo=10*10^-3;
%頻率範圍0~10^7
f=0:1:10000000;
w=2*pi*f;
%計算電壓降
V=R*Vo./sqrt(R^2+(w*L-(1./(w*C))).^2);
plot(f,V);
%電壓降與頻率的關係
title('The voltage drop corresponding to frequency.');
%橫坐標是頻率
xlabel ('f (1/s)');
%縱座標是電壓降
ylabel ('Vr (V)');
%開格子
grid on;

%(a) fo=1.01*10^6 , Vr=10^(-2)
%(b) Vr=2*10^(-30)
%(c) f=1.035*10^6