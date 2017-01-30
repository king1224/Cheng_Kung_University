function cc=EX5_30_0340fun(n)

msg = nargchk(1,1,nargin);
error(msg);

cc=zeros(1,n);
for ii=1:n/2;
    x1=random0(1,1);
    x2=random0(1,1);
    while ((x1^2)+(x2^2))>1
        x1=random0(1,1);
        x2=random0(1,1);
    end
    r=(x1^2)+(x2^2);
    y1=sqrt(-2*log(r)/r)*x1;
    y2=sqrt(-2*log(r)/r)*x2;
    cc(2*ii-1:2*ii)=[y1 y2];
end