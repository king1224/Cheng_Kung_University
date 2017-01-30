function dice = random00(m,n)

global iseed 

msg = nargchk(1,2,nargin);
error(msg);

if nargin < 2
    n = m;
end
dice = zeros(m,n);
for ii = 1:m
    
    for jj = 1:n
        iseed = mod(8121*iseed+28411,134456);
        dice(ii,jj) = iseed/134456;
        %fprintf('dice=%2.5f\n',dice(ii,jj));
        if dice(ii,jj)<=0.1666
            fprintf('1\n ');   
         elseif dice(ii,jj)<=0.3333
        fprintf('2\n ');
         elseif dice(ii,jj)<=0.5000
        fprintf('3\n ');
         elseif dice(ii,jj)<=0.6667
             fprintf('4\n ');
         elseif dice(ii,jj)<=0.8333
             fprintf('5\n ');
         else
             fprintf('6\n ');
       end
    end
       
end
        
    
