income=input('Please enter your income:')
fprintf('The health-care tax you have to pay:%d\n',income*0.015);
if income<=6000
    fprintf('You do not need to pay the tax.\n');
elseif income>6000 && income<=20000
    fprintf('The tax you have to pay:%d\n',(income-6000)*0.17);
elseif income>20000 && income<=50000
    fprintf('The tax you have to pay:%d\n',2380+(income-20000)*0.3);
elseif income>50000 && income<=60000
    fprintf('The tax you have to pay:%d\n',11380+(income-50000)*0.42);
elseif income>60000
    fprintf('The tax you have to pay:%d\n',15580+(income-60000)*0.47);
else
    fprintf('Unacceptable number\n');
    
end
  