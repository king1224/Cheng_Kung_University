n=input('Enter the number of input [x y] points�G');%����J�@���h���I
for ii=1:n;%�C���I����Ū���A�s�_��
    temp=input('Enter [x y] pair�G');
    x(ii)=temp(1); y(ii)=temp(2);
end
c=polyfit(x,y,1);
plot(x,y,'bo');%�e�X�U�I
hold on;
xbar=mean(x);%x��ƥ���
ybar=mean(y);%y��ƥ���
yint=ybar-c(1)*xbar;
xmin=min(x); xmax=max(x);%x���̤j�̤p
ymin=c(1)*xmin+yint;%�̤p����k���u�����x��y
ymax=c(1)*xmax+yint;
plot([xmin xmax],[ymin ymax],'r-','linewidth',2);
hold off;
%�[����
title('\bfLeast-Squares Fit');
xlabel('\bf\itx');
ylabel('\bf\ity');
legend('Input data','Fitted line');
grid on;