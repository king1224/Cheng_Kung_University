function result=EX6_18_0340_fun(str)

msg=nargchk(1,1,nargin);
error(msg);

if ~(isstr(str))
error('Your input isn''t string.\n');
else
result=isstrprop(str,'alphanum');
end
end