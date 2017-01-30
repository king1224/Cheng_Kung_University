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
title('原始與濾波');
legend('濾波後結果','原始資料');
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
title('預測後結果');
legend('預測後結果','原始資料');
hold off;

figure(3)
plot(otline-stock);
title('預測與真實的相對誤差');
