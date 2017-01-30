function ot=line2( i,input,n,typ)


line2_1=averageline( round(n/i)+1,input,n );
line2_2=averageline( round(2*n/i)+1,input,n );
line2=(line2_1-line2_2); 
if n>=30
    line2_x=zeros(1,30);
    for i=n-29:n;
    line2_x(i-n+30)=line2(i);
    end
    line2_max=max(line2_x); 
    line2_min=min(line2_x);
else
    line2_max=max(line2); 
    line2_min=min(line2);
end
if (line2_max<=0||line2_min>=0)
    num2=0;
else
    if line2(n-1)>=line2(n)
        if line2(n)>=0  %num2 for §¡½u
            num2=((line2(n)/line2_max)-1)*line2_max;
        else
            num2=(-1+(line2(n)/line2_min))*(-line2_min);
        end
    else
        if line2(n)>=0
            num2=(1-(line2(n)/line2_max))*line2_max;
        else
            num2=(1-(line2(n)/line2_min))*(-line2_min);
        end
    end
end






[line3_2 line3_1]= MACDline( input,n );
line3=(line3_1-line3_2); 

if n>=30
    line3_x=zeros(1,30);
    for i=n-29:n;
    line3_x(i-n+30)=line3(i);
    end
    line3_max=max(line3_x); 
    line3_min=min(line3_x);
else
    line3_max=max(line3); 
    line3_min=min(line3);
end
if (line3_max<=0||line3_min>=0)
    num3=0;
else
    if line3(n-1)>=line3(n)
        if line3(n)>=0  %num for MACD½u
            num3=((line3(n)/line3_max)-1)*line3_max;
        else
            num3=(-1+(line3(n)/line3_min))*line3_min;
        end
    else
        if line3(n)>=0
            num3=(1-(line3(n)/line3_max))*line3_max;
        else
            num3=(1-(line3(n)/line3_min))*line3_min;
        end
    end
end









[line4_1 line4_2]= KDline( input,n );
line4=(line4_1-line4_2);

if n>=30
    line4_x=zeros(1,30);
    for i=n-29:n;
    line4_x(i-n+30)=line4(i);
    end
    line4_max=max(line4_x); 
    line4_min=min(line4_x);
else
    line4_max=max(line4); 
    line4_min=min(line4);
end

if (line4_max<=0||line4_min>=0)
    num4=0;
else
    if (line4_1(n)>=80&&line4_1(n-1)>=80&&line4_1(n-2)>=80)
        num4=line4_max;
    elseif (line4_1(n)<=20&&line4_1(n-1)<=20&&line4_1(n-2)<=20)
        num4=-line4_min;
    elseif (line4_1(n)>=80&&~(line4_1(n-1)>=80&&line4_1(n-2)>=80))
        num4=-line4_min;
    elseif (line4_1(n)<=20&&~(line4_1(n-1)<=20&&line4_1(n-2)<=20))
        num4=line4_max;
    else
        if line4(n-1)>=line4(n)
            if line4(n)>=0  %num4 for KD½u
                num4=((line4(n)/line4_max)-1)*line4_max;
            else
                num4=(-1+(line4(n)/line4_min))*(line4_min);
            end
        else
            if line4(n)>=0
                num4=(1-(line4(n)/line4_max))*line4_max;
            else
                num4=(1-(line4(n)/line4_min))*(line4_min);
            end
        end
    end
end

if typ==1
    ot=num2;
elseif typ==2
    ot=num3;
elseif typ==3
    ot=num4;
else
z=zeros(1,3);
z(1)=abs(num2);
z(2)=abs(num3);
z(3)=abs(num4);
ot=z(1);
if z(2)<z(1)&&z(2)~=0
    ot=z(2);
end
if z(3)<ot&&z(3)~=0
    ot=z(3);
end
end