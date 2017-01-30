function ff=EX5_10_0340fun(k,t)

msg = nargchk(2,2,nargin);
error(msg);

K=1;
for ii=1:k
    K=K*ii; 
end
l=1.6;
ff=exp(-l*t)*((l*t)^k)/K;