%½Ð¥ý©I¥sseed()
x=zeros(1,100);
for ii=1:100
x(ii)=feval('sin',(ii-1)*0.05);
temp=random0(1,1);
x(ii)=x(ii)+(temp/50);
end
xxx=diffff(x,0.05);
yyy=zeros(1,99);
for ii=1:99
yyy(ii)=feval('cos',(ii-1)*0.05);
end

zzz=xxx-yyy;
plot(xxx,'g');
hold on;
plot(yyy,'m');
plot(zzz,'k');
hold off;
legend('Our cos','Real cos','The different');