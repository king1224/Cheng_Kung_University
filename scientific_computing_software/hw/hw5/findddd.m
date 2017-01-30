function [xmin,min_value,xmax,max_value]=findddd(first_value,last_value,num_steps,func)

n=(last_value-first_value)/num_steps;

nn=first_value;
a=func(1);
ccc=a;
cc=nn;
ddd=a;
dd=nn;

for ii=1:num_steps
nn=first_value+ii*n;
a=func(ii+1);

if a<ccc
 ccc=a;
 cc=nn;
end
if a>ddd
 ddd=a;
 dd=nn;
end
end

xmin=ccc;
min_value=cc;
xmax=ddd;
max_value=dd;