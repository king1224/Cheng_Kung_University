R=100;
L=0.01;
C=0.25e-9;
f=1e+5:1:1e+7;
Zc=-j/2/pi/C./f;
I=120./(R+i*2*pi.*f*L-Zc);

figure(1)
plot(f,abs(I));
xlabel('頻率');
ylabel('電流');
title('電流對頻率作圖(線性-線性)');
grid on;
figure(2)
semilogx(f,abs(I));
xlabel('頻率');
ylabel('電流');
title('電流對頻率作圖(對數-線性)');
grid on;
figure(3)
ang=angle(I);
plot(f,ang);
xlabel('頻率');
ylabel('相角');
title('電流相角對頻率作圖(線性-線性)');
grid on;
figure(4)
semilogx(f,ang);
xlabel('頻率');
ylabel('相角');
title('電流相角對頻率作圖(對數-線性)');
grid on;

figure(5)
subplot(1,2,1);
semilogx(f,abs(I));
title('電流對頻率作圖');
grid on;
subplot(1,2,2);
semilogx(f,ang);
title('電流相角對頻率作圖');
grid on;