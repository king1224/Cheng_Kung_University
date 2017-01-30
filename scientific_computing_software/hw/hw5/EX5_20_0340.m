A=[1 31;11 101;-6 36;17 -17;-23 0;0 10;5 -8;1 -1;-1 -1];
tic
B=sortrows(A);
fprintf('標準函式的時間：');
toc

array1=[1 11 -6 17 -23 0 5 1 -1];
array2=[31 101 36 -17 0 10 -8 -1 -1];
tic
array1_OK=ssort(array1);
array2_OK=zeros(1,9);
for ii=1:9
    for jj=1:9
        if array1_OK(ii)==array1(jj)
            array1(jj)=-99999999;
            array2_OK(ii)=array2(jj);
            break;
        end
    end
end
C=[array1_OK' array2_OK'];
fprintf('我們函式的時間：');
toc
fprintf('標準函式的答案：');
B
fprintf('我們函式的答案：');
C