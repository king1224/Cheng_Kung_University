%f1�G�Ĥ@�ӰT���W�v f2�G�ĤG�ӰT���W�v
%�]�w�nL�BC�BR�BVo�Bf1�Bf2
L=0.25*10^-3;
C=0.1*10^-9;
R=50;
Vo=1;
f1 = 1000*10^3;
f2 = 950*10^3;
w1=2*pi*f1;
w2=2*pi*f2;
%�p��Ĥ@���W�v(f1)�βĤG���W�v(f2)���q����(Vr1,Vr2)
Vr1 = R*Vo./sqrt(R^2+(w1*L-(1./(w1*C))).^2);
Vr2 = R*Vo./sqrt(R^2+(w2*L-(1./(w2*C))).^2);
fprintf('The Vr1= %1.10f \n',Vr1);
fprintf('The Vr2= %1.10f \n',Vr2);
%�p��\�v by P=Vr^2/R , R=50
P1 = (Vr1)^2 / R;
P2 = (Vr2)^2 / R;
%�L�X�ӧO�\�v
fprintf('The P1= %1.10f \n',P1);
fprintf('The P2= %1.10f \n',P2);
%�Τ�����ܥ\�v���
dB = 10 * log10(P1/P2);
fprintf('The ratio of P1 and P2 in dB is %3.10f \n',dB);
%%%  ���I��10��