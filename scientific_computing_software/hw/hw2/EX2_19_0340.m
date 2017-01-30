%f1：第一個訊號頻率 f2：第二個訊號頻率
%設定好L、C、R、Vo、f1、f2
L=0.25*10^-3;
C=0.1*10^-9;
R=50;
Vo=1;
f1 = 1000*10^3;
f2 = 950*10^3;
w1=2*pi*f1;
w2=2*pi*f2;
%計算第一個頻率(f1)及第二個頻率(f2)的電壓降(Vr1,Vr2)
Vr1 = R*Vo./sqrt(R^2+(w1*L-(1./(w1*C))).^2);
Vr2 = R*Vo./sqrt(R^2+(w2*L-(1./(w2*C))).^2);
fprintf('The Vr1= %1.10f \n',Vr1);
fprintf('The Vr2= %1.10f \n',Vr2);
%計算功率 by P=Vr^2/R , R=50
P1 = (Vr1)^2 / R;
P2 = (Vr2)^2 / R;
%印出個別功率
fprintf('The P1= %1.10f \n',P1);
fprintf('The P2= %1.10f \n',P2);
%用分貝表示功率比值
dB = 10 * log10(P1/P2);
fprintf('The ratio of P1 and P2 in dB is %3.10f \n',dB);
%%%  約衰減10倍