lc=8;%纜繩長
lp=8;%桿子長
w=200*0.45359*9.8;%物重(公斤重)

d=1:7;%距離d
temp=sqrt(lp^2 - d.^2);%先儲存根號的數

T=w*lc*lp./d./temp;%張力T的公式
plot(d,T);%畫出來
%加一些註解
title('纜繩張力對距離的函數圖');
xlabel('距離d');
ylabel('張力T');
grid on;