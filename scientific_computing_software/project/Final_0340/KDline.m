function [out1,out2]= KDline( input,n )
out1=zeros(1,n);
out2=zeros(1,n);
RSV=zeros(1,n);

for z=1:8;
    RSV(z)=50;out1(z)=50;out2(z)=50;
end

for z=9:n;
    max=0;min=500000;
    for b=0:8
        if(input(z-b)>max) max=input(z-b);
        end
    end
    for s=0:8
        if(input(z-s)<min) min=input(z-s);
        end
    end
    RSV(z)=(input(z)-min)/(max-min)*100;
out1(z)=(2/3)*out1(z-1)+RSV(z)/3;
out2(z)=(2/3)*out2(z-1)+out1(z)/3;
end