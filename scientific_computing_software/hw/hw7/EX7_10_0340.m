function res=EX7_10_0340(a,b)
msg=nargchk(1,2,nargin);
error(msg);
che1=isstruct(a);
che2=isstr(b);
if che1==0||che2==0
    error('��J��ƫ��A���~');
else
    res='';
    leng=length(a);
    for ii=1:leng
        tmp=getfield(a,{ii},b);
        res=[res tmp];
    end
end
fprintf('%s\n',res);
end