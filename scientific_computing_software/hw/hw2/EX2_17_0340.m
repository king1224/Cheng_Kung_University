%輸入電感
L=input('請輸入電感(H)：');
%輸入電容
C=input('請輸入電容(F)：');
%先用一個變數儲存根號LC
a=sqrt(L*C);
%算出頻率
fo=1/(2*pi*a)