%binomial distribution
fprintf('The answer by using binomial distribution is¡G\n%f\n',binocdf(0,200,0.03));
%Poisson distribution
%¦]¬°p->0¡A¥ÎPoisson approximation¡Ap(x,u)¡Au=np=0.03*200=6
fprintf('The answer by using Poisson approximation is¡G\n%f\n',poisspdf(0,6));

%for binomial probability distribution
x=[binocdf(0,200,0.03) binocdf(1:200,200,0.03)-binocdf(0:199,200,0.03)];
%for Poisson probability distribution
y=poisspdf(0:200,6);

a=0:200;
plot(a,x,'r');
hold on;
plot(a,y);
plot(a,x-y,'g');
xlabel('The number of diodes failure');
ylabel('The probability');
legend('binomial probability distribution','Poisson probability distribution');
title('The probability distribution of diodes failure');
hold off;