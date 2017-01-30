R=16000;
C=1.0e-6;
f=1:2:1000;
res=1./(1+j*2*pi*f*R*C);
amp=abs(res);
phase=angle(res);
subplot(2,1,1);
loglog(f,amp);
title('Amplitude Response');
xlabel('Frequency(Hz)');
ylabel('Output/Input Ratio');
grid on;

subplot(2,1,2);
semilogx(f,phase);
title('Phase Response');
xlabel('Frequency(Hz)');
ylabel('Output-Input Phase(rad)');
grid on;