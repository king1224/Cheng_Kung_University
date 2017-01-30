fid=fopen('EX8_02out.dat','w');
fprintf(fid,'                                            ¹ï¼Æªí\n');
aa=['       ' '    X.1   ' '   X.2   ' '   X.3   ' '   X.4   ' '   X.5   ' '   X.6   ' '   X.7   ' '   X.8   ' '   X.9   '];
fprintf(fid,'%s',aa);
fprintf(fid,'\n');
for jj=1:10
    bb(1)=jj;
    for ii=2:10
        bb(ii)=log10(jj+(ii-1)*0.1);
    end
    fprintf(fid,'%f ',bb);
    fprintf(fid,'\n');

end
fclose(fid);