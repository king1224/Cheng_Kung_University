d1 = [6.72 6.77 6.82 6.70 6.78 6.70 6.62 6.75];
d2 = [6.66 6.66 6.64 6.76 6.73 6.80 6.72 6.76];
d3 = [6.76 6.68 6.66 6.62 6.72 6.76 6.70 6.78];
d4 = [6.76 6.67 6.70 6.72 6.74 6.81 6.79 6.78];
d5 = [6.66 6.76 6.76 6.72];
d  = [d1 d2 d3 d4 d5];
M = mean(d);
fprintf('The sample mean is: %f\n',M);
S = std(d);
fprintf('The sample standard deviation is: %f\n',S);

[n,x]=hist(d,[6.62:0.04:6.82]);
bar(x,n/sum(n));
set(gca,'xtick',[6.62:0.04:6.82]);
xlabel('Sample');
ylabel('Relative frequency');