function ot=lineout(i,stock,n,typ)
tmp=zeros(1,n);
for ii=1:n
    tmp(ii)=line2(i,stock,ii,typ);
end
ot=zeros(1,n);
for ii=1:n
    ot(ii)=tmp(ii);
end
end