x=zeros(1,5);
y=zeros(1,5);
for ii=1:5
    x(ii)=ii;
    y(ii)=EX5_10_0340fun(ii,1);
end
plot(x,y);
xlabel('¨®½ø');
ylabel('¾÷²v');
grid on;