function rr=rayleigh(n,m)

msg = nargchk(1,2,nargin);
error(msg);

if nargin<2
    m=n;
end

rr=zeros(n,m);

for ii=1:n
    for jj=1:m
        n=EX5_30_0340fun(2);
        rr(ii,jj)=sqrt(n(1)^2+n(2)^2);
    end
end