a=sprandn(100,100,0.05);
for ii=1:100
    a(ii,ii)=1;
end
b=sprand(100,1,1);

a_full=full(a);
b_full=full(b);

spy(a_full);
whos
fprintf('����}�C������Ĳv\n\n');
aa=a^(-1);
tic
fprintf('�}���}�C�Ҫ᪺�ɶ�\n');
x=aa*b;
toc

tic
fprintf('����}�C�Ҫ᪺�ɶ�\n');
y=aa*b_full;
toc

fprintf('����}�C�����\n');