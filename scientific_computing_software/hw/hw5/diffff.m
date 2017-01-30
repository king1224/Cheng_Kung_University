function cc=diffff(x,dx)
if dx>0
n=length(x);
for ii=1:n-1
cc(ii)=(x(ii+1)-x(ii))/dx;
end

else
error('dx should > 0.\n');
end