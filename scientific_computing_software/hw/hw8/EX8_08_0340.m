%�n���гy��J�ɮ� .txt
%�H123.txt���d��
n=input('�п�J�nŪ������ƼƥءG');
str=input('�п�J�n�}�Ҫ��ɮצW�١G','s');
fid=fopen(str,'r');
aa=fscanf(fid,'%f',n);
bb=round(aa);
fclose(fid);
str=input('�п�J�n��X���ɮצW�١G','s');
while exist(str,'file')
    tmp=input('���ɮפw�s�b�A�аݬO�_�R���H Y/N  ','s');
    if tmp=='Y'
        fid=fopen(str,'w');
        break;
    else
        str=input('�п�J�n��X���ɮצW�١G','s');
    end
end
if ~(exist(str,'file'))
fid=fopen(str,'w');
end
fprintf(fid,'%d ',bb);
fclose('all');