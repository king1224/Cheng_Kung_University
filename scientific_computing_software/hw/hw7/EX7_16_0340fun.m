function res = EX7_16_0340fun( t,y )
if ((t>=0&&t<1)||(t>=2&&t<3)||(t>=4&&t<5))
    res=1-y;
elseif ((t>=1&&t<2)||(t>=3&&t<4)||(t>=5&&t<6))
        res=-1-y;
else
        res=-y;
end
end

