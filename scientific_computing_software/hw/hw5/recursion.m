function cc=recursion(x,y)
global P
aaa=1;
msg = nargchk(2,2,nargin);
error(msg);

if x==1
cc=y;
else
for ii=2:x
aaa=aaa*(1-y);
end
cc=aaa*y+recursion(x-1,y);
end