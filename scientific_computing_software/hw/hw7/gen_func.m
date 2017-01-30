function fhandle = gen_func( a,b,c )
fhandle=@eval_func;
    function aas= eval_func(x)
    aas=a*x.^2+b*x+c;
    end
end