disp('Enter your value one by one.If all done,please enter -1.')
%����J�Ĥ@�ӼƦr �~�వwhile�j��
x=input('Enter the first value�G');
%���w�q�ܼ�
sumx=0; sumxx=1; n=0;
while x>=0
	sumx=sumx+x;%�x�s�`�M�A�ΨӺ��ƥ���
	sumxx=sumxx*x;%�x�s���n�A�ΨӺ�X�󥭧�
	n=n+1;%�x�s�@���X�Ӽ�
	x=input('Enter the next value�G');
end

a=sumx/n;%��N����
b=sumxx^(1/n);%�X�󥭧�
fprintf('the Arithmetic mean=%f\nthe Geometric mean=%f\n',a,b);