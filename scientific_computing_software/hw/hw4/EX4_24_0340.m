disp('Enter your value one by one.If all done,please enter -1.')
%先輸入第一個數字 才能做while迴圈
x=input('Enter the first value：');
%先定義變數
sumx=0; sumxx=1; n=0;
while x>=0
	sumx=sumx+x;%儲存總和，用來算算數平均
	sumxx=sumxx*x;%儲存乘積，用來算幾何平均
	n=n+1;%儲存共有幾個數
	x=input('Enter the next value：');
end

a=sumx/n;%算術平均
b=sumxx^(1/n);%幾何平均
fprintf('the Arithmetic mean=%f\nthe Geometric mean=%f\n',a,b);