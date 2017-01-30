%binomial distribution
fprintf('The answer by using binomial distribution is¡G\n%f\n',binocdf(13,18,0.7) - binocdf(9,18,0.7));
%hypergeomeric distribution
fprintf('The answer by using hypergeomeric distribution is¡G\n%f\n',sum(hygepdf(10:13,27000,18900,18)));

%for binomial probability distribution
x=[binocdf(0,18,0.7) binocdf(1:18,18,0.7)-binocdf(0:17,18,0.7)];
%for hypergeomeric probability distribution
y=hygepdf(0:18,27000,18900,18);


a=0:18;
plot(a,x,'r');
hold on;
plot(a,y);
plot(a,x-y,'g');
xlabel('The number of students that disapprove smoking.');
ylabel('The probability');
legend('binomial probability distribution','hypergeomeric probability distribution');
title('The probability distribution of students that disapprove smoking');
hold off;