weight=input('Please input the weight(pound)¡G\n')
if weight<=2
    fprintf('It costs = 15.00\n');
elseif weight>2 && weight<=70,
    fprintf('It costs = %f\n',15.00+5*(weight-2));
elseif weight>70 && weight<=100,
    fprintf('It costs = %f\n',30.00+5*(weight-2));
else weight>100,
    fprintf('No service\n');
        end
        
