#include <stdio.h>

int bitrow=0;

int bucket_union(char bucket[][1000], char tmp[], int pos, int maxn, int n, int bitmap[][1000]);
int new_mapping(int bestrow, int bitrow, char ttmmpp[], char bucket[][1000], int bitmap[][1000]);
void print_result (char bucket[][1000], int bitmap[][1000], int max_num2 , int tmpn);
int countsame(char ttmmpp[],char bucket[][1000], int row);
int insert(char ttmmpp[],char bucket[][1000], int row);
int countspace(char bucket[][1000], int row, int n);
int findbestrow(char bucket[][1000], int n, int ttmmppnum, char ttmmpp[]);



int main()
{
    int maxn=0,tmpn=0,max_num2=1,read_pos=0;//maxn�Ψ��x�s�̪��@�ժ��ƾڪ��סAtmpn�ΨӼȦs�U����׸�maxn����A��Ψ��x�s�ϥΪ̿�J��n�Amax_num2�Ψӭp�⦳�X�C�ƾڡAread_pos�ΨӬ���tmp����m�A��J�ө�itmp����
    int i,j,k;
    FILE *fop;
    char in[1024];//�Ȧs��J�A�@��Ū�i�@�C 
    char tmp[8192];//�x�s��������J�Ain�������tmp 
	//����l�Ƽƾ� 
    for(k=0;k<8192;k++) tmp[k]=0;
    for(k=0;k<1024;k++) in[k]=0;
	//�}���ɮ� 
    fop=fopen("buckets.in","r");
	//�p�G�}�l�ɮץ��ѡA��ܥ��� 
    if (fop==NULL){
        printf( "Open failure" );
        return 1;
    }else{
        while(fgets(in, 1024, fop)!=NULL)//�@����@�զr��A����@�Cbucket 
        {
                i=0;
                while(in[i]!=0)//��o��r�굲�����eŪ�쪺�ƾڡA���s�itmp 
                {
                        if(in[i]!=13){
                        tmp[read_pos]=in[i];
                        read_pos++;
                        in[i]=0;
                        i++;}
                        else {in[i]=0; i++;}
                        }
                }
        }
    i=0;
	while(tmp[i]!=0)//�p��n�Ȧܤ֭n�O�h�֡A�J��ť�tmpn�N�[�@�A�J�촫��tmpn�N�k�s�A��X�C�@�檺�ƾڦ��X�աA�̤j���s��maxn
    {
        if(tmp[i]==32||tmp[i]==10)
        {tmpn++;}
        if(tmp[i]==10&&tmpn>=maxn)
        {max_num2++;maxn=tmpn;tmpn=0;}
        else if(tmp[i]==10&&tmpn<maxn)
        {max_num2++;tmpn=0;}
        i++;
    }

        if(tmpn>maxn) maxn=tmpn+1;

        printf("�п�Jn��(n���ӭn�j�󵥩�%d)�G",maxn);
        scanf("%d",&tmpn);

        if(tmpn<maxn){printf("wrong input."); return 0;}//��J��n�ȿ��~�n����



        char bucket[max_num2][1000];//��J���X�C�A��X��bucketS�ܦh�N���X�C
        int bitmap[max_num2][1000];//��J���X�C�A��X��bitmap�N���X�C
        int tmp_pos=0;//�n�N�U�ռƾ�union��sbucket�Atmp_pos�����{�b�B�z����@�� 
        for(j=0;j<max_num2;j++)
        for(k=0;k<1000;k++)
        {bucket[j][k]=bitmap[j][k]=0;}//��l�� 

        while(tmp[tmp_pos]!=0)//�@���@�C�A��U�Cunion��bucket�̭��A new_mapping�b�o�禡�̭��A��X��mapping�]�@�_�b�o�̰����F 
        { 
        	tmp_pos+=bucket_union(bucket,tmp,tmp_pos,maxn,tmpn,bitmap);
        }
    fclose(fop);

	print_result(bucket, bitmap, max_num2 , tmpn);//�L�X���G 

    return 0;
}


int bucket_union(char bucket[][1000], char tmp[], int pos, int maxn, int n, int bitmap[][1000])
{
        char ttmmpp[1000];//�ΨӼȦs�ݭn��union���@�C 
        int num=0,bestrow,ttmmppnum=0;//num�ΨӰO�������x�s�bttmmpp�����Ӧ�m�A��J�h�֦r���Abestrow�ΨӰO���o�@�C�n�s�bbucket�����Attmmppnum�������C���X�ռƾ� 
        int i,j;
        for(i=0;i<1000;i++)ttmmpp[i]=0;//��l�� 
        while(tmp[pos]!=0&&tmp[pos]!=10)//�qtmp�ƻs��ƨ�ttmmpp 
        {
                ttmmpp[num]=tmp[pos];
                num++; pos++;
        }
        ttmmpp[num]=32;
        i=0;
        while(ttmmpp[i]!=0){if(ttmmpp[i]==32) ttmmppnum++; i++;}//�J��Ů�ttmmppnum�N�[�@�A�i��X���X�ռƦr 

        bestrow=findbestrow(bucket, n, ttmmppnum, ttmmpp);//���Ӧs��bbuckets.out���@�C 
        j=insert(ttmmpp,bucket,bestrow);//���J�����Ӧs�񪺨��@�C 
        bitrow=new_mapping(bestrow,bitrow,ttmmpp,bucket,bitmap);//�P�ɶ��K��Xmapping����ƨ�bitmap 
        return num+1;//��Jnum�r���᪺�U�@�Ӧr���O����r���Anum+1�r���~�O�ĤG�C���_�l�I 
}


//����{�b�n�B�z���@�C�ƾڡA�Pbuckets.out�̪��C�@�C�����Ʃ� 
int countsame(char ttmmpp[],char bucket[][1000], int row)
{
        int pos1=0,pos2=0,z=0,match=0,same=0,length=0;//pos1������e�n�B�z���C��m�Apos2����bucket�Y�@�C����m�Amatch�ˬd�O�_�Ʀr���ۦP�Asame�N���X�ռƦr�ۦP�Alength�p��o�ռƦr������ 
        while(ttmmpp[pos1]!=0)//�B�z���e�n�B�z���o�C�B�z�� 
        {
                length=0;
                while(ttmmpp[pos1+length]!=32) length++;//�ťդ��e���X��ơA���״N�O�h�� 
                while(bucket[row][pos2]!=0&&match!=length)//��Ө�bucket�̫�@��A�Τw�g���ۦP���Ʀr�աC 
                {
                        for(z=0;z<length;z++)
                        {if(ttmmpp[pos1+z]==bucket[row][pos2+z]) match++;}
                                if(match==length) {same+=1;} 
                                else {match=0;  pos2=pos2+length+1;}
                }
                pos1=pos1+length+1;//���U�@�ռƦr�եh�t�� 
                pos2=match=0;//��l�� 
        }
        return same;
}





//�N��e�Ʀr�մ��J��bucket�� 
int insert(char ttmmpp[],char bucket[][1000], int row)
{
        int pos1=0,pos2=0,z,match=0,nullpos=0,num=0,length=0;//pos1�����n���J���C�B�z����̡Apos2����bucket���C���Ө���̡Amatch�����ˬd���Ʀr�լO�_�ۦP�Anullpos����bucket���Ŧ�q���̶}�l,num�����B�z�F�h�ֲռƦr��,length�����Ʀr�ժ��� 
        while(bucket[row][nullpos]!=0) nullpos++;
        while(ttmmpp[pos1]!=0)//�B�z��n��J���C�B�z�� 
        {
                length=0;
                while(ttmmpp[pos1+length]!=32) length++;
                while(match!=length)//�M��O�_�w�g���ۦP�Ʀr�զb�Pbucket�����C 
                {
                        for(z=0;z<length;z++)
                        {if(ttmmpp[pos1+z]==bucket[row][pos2+z]) match++;}
                        if(match!=length&&bucket[row][pos2+length+1]==0)//�Y����bucket�̫��٨S���ۦP�ƾڡA�N�o�ռƾڴ��bbucket����᭱ 
                        {
                                for(z=0;z<length+1;z++){bucket[row][nullpos+z]=ttmmpp[pos1+z];}
                                nullpos=nullpos+length+1;
                                match=length;
                        }
                        if(match!=length){pos2=pos2+length+1; match=0;}
                        if(match==length) num++;
                }
                pos1=pos1+length+1;
                match=pos2=0;
        }
        return num;
}



//�p��bucket�o�@�C�Ѧh�֦�m 
int countspace(char bucket[][1000], int row, int n)
{
        int space=0,i;//space�Ψӭp��h�֪Ŧ�
        while(bucket[row][i]!=0)//���⦹bucket�����h�ּƾ�
        {if(bucket[row][i]==32) {space++;} i++;} 
        space=n-space;//����Jbucket�s��n���ƾڡA������e�����A�Y�Ѫ��Ŧ� 
        return space;
}



//������ӭn���J��bucket�����@�C�A�ڬO�M��̦h�ۦP�ƪ��C 
int findbestrow(char bucket[][1000], int n, int ttmmppnum, char ttmmpp[])
{
        int row=0,ccc,ddd,bestrow=0,bestsame=0,in=0;
        while(bucket[row][0]!=0)//��Ө�bucket���̫�@�C 
        {//��X�P�C�C���h�֬ۦP�A�o�C�Ŷ���������A���̦h�ۦP�Ŷ��]������ 
                ccc=countsame(ttmmpp,bucket,row);
                ddd=countspace(bucket,row,n);
                if(ttmmppnum-ccc<ddd&&ccc>=bestsame){bestsame=ccc;      bestrow=row;    in=1;}
                row++;
        }
        if(in==0) bestrow=row;//�p�G���S���ۦP�ΪŶ��������A��bbucket�̷s�C 

        return bestrow;
}




//��Xmapping.out 
int new_mapping(int bestrow, int bitrow, char ttmmpp[], char bucket[][1000], int bitmap[][1000])
{
        int samepos=1,pos1=0,pos2=0,match=0,z,length=0;//samepos�ΨӰO��bitmap����m�Apos1�ΨӰO���n��Ӫ��C����m�Apos2����bucket�C����m�Amatch�����ƾڬO�_�ۦP�Alength�����Ʀr�ժ��� 
        bitmap[bitrow][0]=bestrow;
        while(ttmmpp[pos1]!=0)
        {
                length=0;
                while(ttmmpp[pos1+length]!=32) length++;
                while(match!=length&&bucket[bestrow][pos2]!=0)//����t�令�\��bucket�]������ 
                {
                        for(z=0;z<length;z++)
                        {if(ttmmpp[pos1+z]==bucket[bestrow][pos2+z]) match++;}
                        if(match!=length){pos2=pos2+length+1; match=0;samepos++;}
                        if(match==length) bitmap[bitrow][samepos]=1;
                }
                pos1=pos1+length+1;
                match=pos2=0;
                samepos=1;
        }
        return bitrow+1;
}


//�L�Xbucket��bitmap�x�}��buckets.out�Mmapping.out 
void print_result(char bucket[][1000], int bitmap[][1000], int max_num2 , int tmpn)
{
	int i,j;
	FILE *fip1;//�}��buckets.out 
    fip1=fopen("buckets.out","w");
    i=j=0;
    while(bucket[i][0]!=0)//�L��bucket�̫�@�C 
    {
		while(bucket[i][j+1]!=0)//�C�C�L��̫�@�Ӧr�� 
	        {
                if(bucket[i][j]==32) fprintf(fip1," ");
                else if(bucket[i][j]>=48&&bucket[i][j]<=57)
                {
                    bucket[i][j]=bucket[i][j]-48;
                    fprintf(fip1,"%d",bucket[i][j]);
                }
                j++;
            }
        if(bucket[i+1][0]!=0)fprintf(fip1,"\n");
        i++;
        j=0;
    }
        fclose(fip1);

	FILE *fip2;//�}��mapping.out 
    fip2=fopen("mapping.out","w");
    for(i=0;i<max_num2;i++)//��J���X�C�A��X�N���X�C 
    {
        fprintf(fip2,"%d ",bitmap[i][0]);
        for(j=1;j<=tmpn;j++)//tmpn�ثe�ȬO��ɿ�J��n 
        {
                fprintf(fip2,"%d",bitmap[i][j]);
                }
                putc('\n',fip2);
        }

        fclose(fip2);
}

