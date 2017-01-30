arr=rayleigh(1,20000);
ss=mean(arr);
fprintf('¥­§¡­È=%1.5f\n',ss);

ss=std(arr);
fprintf('¼Ð·Ç®t=%1.5f\n',ss);

hist(arr,100);