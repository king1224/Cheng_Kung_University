for ii=1:9
string=['Enter value to array1-' int2str(ii) ':'];
array1(ii)=input(string);
end


for ii=1:9
string=['Enter value to array2-' int2str(ii) ':'];
array2(ii)=input(string);
end

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
fprintf('array1_OK=');
fprintf('%f ',array1_OK);
fprintf('\n');
fprintf('array2_OK=');
fprintf('%f ',array2_OK);
fprintf('\n');