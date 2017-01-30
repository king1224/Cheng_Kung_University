function [out1,out2]= MACDline( input,n )
out1=zeros(1,n);
out2=zeros(1,n);

average1=averageline(12,input,n);
average2=averageline(26,input,n);

for z=1:n
    out2(z)=average1(z)-average2(z);
end

if n>=8
    for z=1:8
        out1(z)=out2(z);
    end
else
    for z=1:n
        out1(z)=out2(z);
    end
end

out1=averageline(9,out2,n);

end

