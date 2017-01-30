a=input('請輸入字串：\n','s');
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
fprintf('\n1：字母　2：數字　3：空白　0：其他字元\n');