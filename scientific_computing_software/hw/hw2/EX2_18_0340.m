%�]�w�nL�BC�BR�BVo
L=0.25*10^-3;
C=0.1*10^-9;
R=50;
Vo=10*10^-3;
%�W�v�d��0~10^7
f=0:1:10000000;
w=2*pi*f;
%�p��q����
V=R*Vo./sqrt(R^2+(w*L-(1./(w*C))).^2);
plot(f,V);
%�q�����P�W�v�����Y
title('The voltage drop corresponding to frequency.');
%��ЬO�W�v
xlabel ('f (1/s)');
%�a�y�ЬO�q����
ylabel ('Vr (V)');
%�}��l
grid on;

%(a) fo=1.01*10^6 , Vr=10^(-2)
%(b) Vr=2*10^(-30)
%(c) f=1.035*10^6