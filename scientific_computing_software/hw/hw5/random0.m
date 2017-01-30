%用到random0函式之前 請先呼叫seed函式 設定初始值 ex: seed(20)
function ran=random0(m,n)
global iseed

msg = nargchk(1,2,nargin);
error(msg);

if nargin<2
    n=m;
end

ran=zeros(m,n);
for ii=1:m
    for jj=1:n
        iseed=mod(8121*iseed+28411,134456);
        ran(ii,jj)=(iseed-67228)/67228;
    end
end