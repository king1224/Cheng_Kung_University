a=input('�п�J�r��G\n','s');
if ~(isstr(a))
    error('Your input isn''t string.\n');
else
    aa=isstrprop(a,'digit');
    bb=isstrprop(a,'alphanum');
    cc=isstrprop(a,'wspace');
end
double(aa); double(bb); double(cc);
b=aa+bb+3*cc;
fprintf('%d',b);
fprintf('\n1�G�r���@2�G�Ʀr�@3�G�ťա@0�G��L�r��\n');