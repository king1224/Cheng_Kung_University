function out = averageline( i,input,n )

%if i==0
%    i=i+1;
%end

if i>n
    i=n;
end

out=zeros(1,n);
for z=1:i-1
        out(z)=input(z);
end
for z=1:i
    out(i)=out(i)+input(z);
end
out(i)=out(i)/i;

for ii=i+1:n
    out(ii)=out(ii-1)+(input(ii)-input(ii-i))/i;
end
