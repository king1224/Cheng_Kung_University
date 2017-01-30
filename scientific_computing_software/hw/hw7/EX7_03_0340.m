a=sprandn(100,100,0.05);
for ii=1:100
    a(ii,ii)=1;
end
b=sprand(100,1,1);

a_full=full(a);
b_full=full(b);

spy(a_full);
whos
fprintf('完整陣列比較有效率\n\n');
aa=a^(-1);
tic
fprintf('稀疏陣列所花的時間\n');
x=aa*b;
toc

tic
fprintf('完整陣列所花的時間\n');
y=aa*b_full;
toc

fprintf('完整陣列比較快\n');