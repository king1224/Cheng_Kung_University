arr=rayleigh(1,20000);
ss=mean(arr);
fprintf('������=%1.5f\n',ss);

ss=std(arr);
fprintf('�зǮt=%1.5f\n',ss);

hist(arr,100);