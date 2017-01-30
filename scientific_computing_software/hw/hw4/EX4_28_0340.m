%先訂有幾個元件數
n=input('Enter the number of MTBF：');
%先定義變數
a=0;
for ii=1:n
	x=input('Enter the next MTBF：');
	a=a+(1/x);%先計算公式中的分母	
end
answer=1/a;%因為a是分母 所以答案等於1/a
fprintf('the answer=%f\n',answer);