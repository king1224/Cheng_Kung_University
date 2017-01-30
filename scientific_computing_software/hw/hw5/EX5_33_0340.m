fff=rayleigh(1,1000000);
fff=fff/mean(fff)*10;

dB=5:13;
v=10*10.^(dB./20);
for ii=1:9
    count=0;
    for jj=1:1000000
        if fff(jj)>v(ii)
            count=count+1;
        end
    end
    err=count./1000000;
    fprintf('第%d次警報=%1.10f\n',ii,err);
end