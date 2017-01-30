function x=EX7_04_0340(varargin)
msg=nargchk(1,Inf,nargin);
error(msg);
x=zeros(1,nargin);
for ii=1:nargin
    x(ii)=sum(varargin{ii}(:));
    fprintf('the %d input sum=%f\n',ii,x(ii));
end
end