function tmp=movave( N,stock,i )
tmp=zeros(1,i);

for n=1:N-1
    tmp(n)=stock(n);
end
for n=1:N
    tmp(N)=tmp(N)+stock(n);
end
tmp(N)=tmp(N)/N;

for ii=N+1:i
    tmp(ii)=tmp(ii-1)+(stock(ii)-stock(ii-N))/N;
end