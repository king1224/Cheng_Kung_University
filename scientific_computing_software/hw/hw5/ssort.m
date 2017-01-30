function out=ssort(a)
nvals=size(a,2);
%nval---Number of input values 
for ii=1:nvals-1
iptr=ii;
for jj=ii+1:nvals
if a(jj)<a(iptr)
iptr=jj;
end
end
if ii~=iptr
temp=a(ii);
a(ii)=a(iptr);
a(iptr)=temp;
end
end

out=a;