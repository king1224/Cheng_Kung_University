star=0; eend=2*pi; cc=0.0001; num=eend/cc;

x=star:cc:eend;
y=sin(x);
[xmin min_value xmax max_value]=findddd(star,eend,num,y);
fprintf('When x_value=%f xmin=%f\n',min_value,xmin);
fprintf('When x_value=%f xmax=%f\n',max_value,xmax);