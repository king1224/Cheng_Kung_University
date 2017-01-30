%請先呼叫seed()
arr=EX5_30_0340fun(1000);
ss=std(arr);
fprintf('標準差=%1.5f\n',ss);
hist(arr,100);