function otline=fin( N,stock,i )
if N>i
    msg='N should <= i';
    error(msg);
end
load('stock.mat')
rrr=movave( 5,stock,i );
figure(1)
plot(rrr);
hold on;
plot(stock,'r');
title('��l�P�o�i');
legend('�o�i�ᵲ�G','��l���');
hold off;
otline=zeros(1,i);
if i>=80
    a=lineout(80,rrr,i,4);
else
    a=lineout(N,rrr,i,4);
end

otline(1)=stock(1);
for ii=2:i
    otline(ii)=a(ii-1)+stock(ii-1);
end
figure(2)
plot(otline);
hold on;
plot(stock,'r');
title('�w���ᵲ�G');
legend('�w���ᵲ�G','��l���');
hold off;

figure(3)
plot(otline-stock);
title('�w���P�u�ꪺ�۹�~�t');
