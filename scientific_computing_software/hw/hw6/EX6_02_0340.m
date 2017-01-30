R=100;
L=0.01;
C=0.25e-9;
f=1e+5:1:1e+7;
Zc=-j/2/pi/C./f;
I=120./(R+i*2*pi.*f*L-Zc);

figure(1)
plot(f,abs(I));
xlabel('�W�v');
ylabel('�q�y');
title('�q�y���W�v�@��(�u��-�u��)');
grid on;
figure(2)
semilogx(f,abs(I));
xlabel('�W�v');
ylabel('�q�y');
title('�q�y���W�v�@��(���-�u��)');
grid on;
figure(3)
ang=angle(I);
plot(f,ang);
xlabel('�W�v');
ylabel('�ۨ�');
title('�q�y�ۨ����W�v�@��(�u��-�u��)');
grid on;
figure(4)
semilogx(f,ang);
xlabel('�W�v');
ylabel('�ۨ�');
title('�q�y�ۨ����W�v�@��(���-�u��)');
grid on;

figure(5)
subplot(1,2,1);
semilogx(f,abs(I));
title('�q�y���W�v�@��');
grid on;
subplot(1,2,2);
semilogx(f,ang);
title('�q�y�ۨ����W�v�@��');
grid on;