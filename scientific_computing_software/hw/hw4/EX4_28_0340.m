%���q���X�Ӥ����
n=input('Enter the number of MTBF�G');
%���w�q�ܼ�
a=0;
for ii=1:n
	x=input('Enter the next MTBF�G');
	a=a+(1/x);%���p�⤽����������	
end
answer=1/a;%�]��a�O���� �ҥH���׵���1/a
fprintf('the answer=%f\n',answer);