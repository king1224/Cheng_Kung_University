%要先創造輸入檔案 .txt
%以123.txt為範本
n=input('請輸入要讀取的資料數目：');
str=input('請輸入要開啟的檔案名稱：','s');
fid=fopen(str,'r');
aa=fscanf(fid,'%f',n);
bb=round(aa);
fclose(fid);
str=input('請輸入要輸出的檔案名稱：','s');
while exist(str,'file')
    tmp=input('此檔案已存在，請問是否刪除？ Y/N  ','s');
    if tmp=='Y'
        fid=fopen(str,'w');
        break;
    else
        str=input('請輸入要輸出的檔案名稱：','s');
    end
end
if ~(exist(str,'file'))
fid=fopen(str,'w');
end
fprintf(fid,'%d ',bb);
fclose('all');