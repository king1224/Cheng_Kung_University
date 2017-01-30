#include <mpi.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "bmp.h"

using namespace std;

#define NSmooth 1000

BMPHEADER bmpHeader;                        
BMPINFO bmpInfo;
RGBTRIPLE **BMPSaveData = NULL;                                       
RGBTRIPLE **BMPData = NULL;
RGBTRIPLE **LocalData = NULL;

int readBMP( char *fileName);
int saveBMP( char *fileName);
void swap(RGBTRIPLE *a, RGBTRIPLE *b);
RGBTRIPLE **alloc_memory( int Y, int X );

//build new type that can send RGBTRIPLE struct in MPI
void Build_mpi_type(unsigned char* a,unsigned char* b,unsigned char* c,MPI_Datatype* input_mpi_type){	
	int arr[3]={1,1,1};
	MPI_Datatype arry[3]={MPI_BYTE,MPI_BYTE,MPI_BYTE};
	MPI_Aint a_add,b_add,c_add;
	MPI_Aint arrdis[3]={0};

	MPI_Get_address(a,&a_add);
	MPI_Get_address(b,&b_add);
	MPI_Get_address(c,&c_add);
	arrdis[1]=b_add-a_add;
	arrdis[2]=c_add-a_add;

	MPI_Type_create_struct(3,arr,arrdis,arry,input_mpi_type);
	MPI_Type_commit(input_mpi_type);
}


int main(int argc,char *argv[])
{
	char *infileName = "input.bmp";
   	char *outfileName = "output1.bmp";
	double startwtime = 0.0, endwtime=0;
	int myid,sz;
	MPI_Datatype input_mpi_type;
	//MPI start
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	
	//Process 0 read file
	if(myid==0){
		if ( readBMP( infileName) )
                cout << "Read file successfully!!" << endl;
        else 
                cout << "Read file fails!!" << endl;
	}
	
	//Brocast the picture's height and width to ohter processes
	MPI_Bcast(&bmpInfo.biHeight,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Bcast(&bmpInfo.biWidth,1,MPI_INT,0,MPI_COMM_WORLD);
	
	//wait and start count time
	MPI_Barrier(MPI_COMM_WORLD);
	startwtime = MPI_Wtime();

	int x=bmpInfo.biHeight/sz;
	int rc[sz],disp[sz];
	//cut and send the pricture to other processes
	//the first and final row only used to give information, won't be smooth
	disp[0]=0;
	for(int i=0;i<(bmpInfo.biHeight)%sz;++i){
		rc[i]=(x+3)*bmpInfo.biWidth;
	}
	for(int i=(bmpInfo.biHeight)%sz;i<sz;++i){
		rc[i]=(x+2)*bmpInfo.biWidth;
	}
	for(int i=1;i<sz;++i){
		disp[i]=disp[i-1]+rc[i-1]-2*bmpInfo.biWidth;
	}
	int Recv_cnt=rc[myid];

	if(myid==0)
    	BMPData = alloc_memory( bmpInfo.biHeight + 2 , bmpInfo.biWidth);
	else
    	BMPData = alloc_memory( rc[myid]/bmpInfo.biWidth, bmpInfo.biWidth);



	if(myid!=0)
    	BMPSaveData = alloc_memory( rc[myid]/bmpInfo.biWidth, bmpInfo.biWidth);

	//build type before use
	Build_mpi_type(&BMPSaveData[0][0].rgbBlue,&BMPSaveData[0][0].rgbGreen,&BMPSaveData[0][0].rgbRed,&input_mpi_type);

	//scatter pricture to other processes
	//if only one process, don't need to send information
	if(sz==1)	swap(BMPSaveData,BMPData);
	else
		MPI_Scatterv(BMPSaveData[0],rc,disp,input_mpi_type,BMPData[0],Recv_cnt,input_mpi_type,0,MPI_COMM_WORLD);

	//start smooth
	for(int count = 0; count < NSmooth ; count ++){
		for(int i = 1; i<rc[myid]/bmpInfo.biWidth-1 ; ++i){
			for(int j =0; j<bmpInfo.biWidth ; ++j){
				int Top = i-1;
				int Down = i+1;
				int Left = j>0 ? j-1 : bmpInfo.biWidth-1;
				int Right = j<bmpInfo.biWidth-1 ? j+1 : 0;

				BMPSaveData[i][j].rgbBlue =  (double) (BMPData[i][j].rgbBlue+BMPData[Top][j].rgbBlue+BMPData[Down][j].rgbBlue+BMPData[i][Left].rgbBlue+BMPData[i][Right].rgbBlue)/5+0.5;
				BMPSaveData[i][j].rgbGreen =  (double) (BMPData[i][j].rgbGreen+BMPData[Top][j].rgbGreen+BMPData[Down][j].rgbGreen+BMPData[i][Left].rgbGreen+BMPData[i][Right].rgbGreen)/5+0.5;
				BMPSaveData[i][j].rgbRed =  (double) (BMPData[i][j].rgbRed+BMPData[Top][j].rgbRed+BMPData[Down][j].rgbRed+BMPData[i][Left].rgbRed+BMPData[i][Right].rgbRed)/5+0.5;
			}
		}
		//swap information here
		//update the first and final row here (cause both of them don't updata by smooth)
		if(sz==1){
			for(int i=0;i<bmpInfo.biWidth;++i){
				BMPSaveData[0][i].rgbBlue=BMPSaveData[bmpInfo.biHeight][i].rgbBlue;
				BMPSaveData[0][i].rgbGreen=BMPSaveData[bmpInfo.biHeight][i].rgbGreen;
				BMPSaveData[0][i].rgbRed=BMPSaveData[bmpInfo.biHeight][i].rgbRed;
				BMPSaveData[bmpInfo.biHeight+1][i].rgbBlue=BMPSaveData[1][i].rgbBlue;
				BMPSaveData[bmpInfo.biHeight+1][i].rgbGreen=BMPSaveData[1][i].rgbGreen;
				BMPSaveData[bmpInfo.biHeight+1][i].rgbRed=BMPSaveData[1][i].rgbRed;
			}
		}
		//if every process sendrecv together
		//the program will hang
		//divide them into two parts
		else{	
			if(myid%2){
				MPI_Sendrecv(BMPSaveData[1],bmpInfo.biWidth,input_mpi_type,myid-1>=0?myid-1:sz-1,0,BMPSaveData[0],bmpInfo.biWidth,input_mpi_type,myid-1>=0?myid-1:sz-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				MPI_Sendrecv(BMPSaveData[rc[myid]/bmpInfo.biWidth-2],bmpInfo.biWidth,input_mpi_type,myid+1<sz?myid+1:0,0,BMPSaveData[rc[myid]/bmpInfo.biWidth-1],bmpInfo.biWidth,input_mpi_type,myid+1<sz?myid+1:0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			}
			else{
				MPI_Sendrecv(BMPSaveData[rc[myid]/bmpInfo.biWidth-2],bmpInfo.biWidth,input_mpi_type,myid+1<sz?myid+1:0,0,BMPSaveData[rc[myid]/bmpInfo.biWidth-1],bmpInfo.biWidth,input_mpi_type,myid+1<sz?myid+1:0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				MPI_Sendrecv(BMPSaveData[1],bmpInfo.biWidth,input_mpi_type,myid-1>=0?myid-1:sz-1,0,BMPSaveData[0],bmpInfo.biWidth,input_mpi_type,myid-1>=0?myid-1:sz-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			}
		}
		swap(BMPSaveData,BMPData);
	}

	//after smooth
	//gatherv here
	for(int i=0;i<sz;++i){
		rc[i]-=2*bmpInfo.biWidth;
	}
	Recv_cnt=rc[myid];
	if(sz==1)	swap(BMPSaveData,BMPData);
	else
		MPI_Gatherv(BMPData[1],Recv_cnt,input_mpi_type,BMPSaveData[1],rc,disp,input_mpi_type,0,MPI_COMM_WORLD);
	//free the type if won't use again
	MPI_Type_free(&input_mpi_type);
 	//save picture
	if(myid==0){
       	if ( saveBMP( outfileName ) )
       	        cout << "Save file successfully!!" << endl;
       	else
       	        cout << "Save file fails!!" << endl;
		//print total time cost
		endwtime = MPI_Wtime();
   		cout << "The smooth times " << NSmooth << endl;
		cout << "The processes number " << sz << endl;
	    cout <<	"The execution time = "<< endwtime-startwtime <<endl ;
	}
	//free memery and finish
 	free(BMPData);
 	free(BMPSaveData);
	free(LocalData);
 	MPI_Finalize();

        return 0;
}


//read file
int readBMP(char *fileName)
{
        ifstream bmpFile( fileName, ios::in | ios::binary );
 
        if ( !bmpFile ){
                cout << "It can't open file!!" << endl;
                return 0;
        }
 
    	bmpFile.read( ( char* ) &bmpHeader, sizeof( BMPHEADER ) );
 
        if( bmpHeader.bfType != 0x4d42 ){
                cout << "This file is not .BMP!!" << endl ;
                return 0;
        }
 
        bmpFile.read( ( char* ) &bmpInfo, sizeof( BMPINFO ) );
        
        if ( bmpInfo.biBitCount != 24 ){
                cout << "The file is not 24 bits!!" << endl;
                return 0;
        }

        while( bmpInfo.biWidth % 4 != 0 )
        	bmpInfo.biWidth++;

        BMPSaveData = alloc_memory( bmpInfo.biHeight + 2, bmpInfo.biWidth);
//add the first row next to final
//add the final row before first
//It's eayier for cut        
		bmpFile.read( (char* )BMPSaveData[1], bmpInfo.biWidth*sizeof(RGBTRIPLE)*bmpInfo.biHeight);

		for(int i=0;i<bmpInfo.biWidth;++i){
			BMPSaveData[0][i].rgbBlue=BMPSaveData[bmpInfo.biHeight][i].rgbBlue;
			BMPSaveData[0][i].rgbGreen=BMPSaveData[bmpInfo.biHeight][i].rgbGreen;
			BMPSaveData[0][i].rgbRed=BMPSaveData[bmpInfo.biHeight][i].rgbRed;
			BMPSaveData[bmpInfo.biHeight+1][i].rgbBlue=BMPSaveData[1][i].rgbBlue;
			BMPSaveData[bmpInfo.biHeight+1][i].rgbGreen=BMPSaveData[1][i].rgbGreen;
			BMPSaveData[bmpInfo.biHeight+1][i].rgbRed=BMPSaveData[1][i].rgbRed;
		}
	
        bmpFile.close();
 
        return 1;
 
}


//save file
int saveBMP( char *fileName)
{
        if( bmpHeader.bfType != 0x4d42 ){
                cout << "This file is not .BMP!!" << endl ;
                return 0;
        }
        
        ofstream newFile( fileName,  ios:: out | ios::binary );
 
        if ( !newFile ){
                cout << "The File can't create!!" << endl;
                return 0;
        }
 	
        newFile.write( ( char* )&bmpHeader, sizeof( BMPHEADER ) );

        newFile.write( ( char* )&bmpInfo, sizeof( BMPINFO ) );

        newFile.write( ( char* )BMPSaveData[1], bmpInfo.biWidth*sizeof(RGBTRIPLE)*bmpInfo.biHeight );

        newFile.close();
 
        return 1;
 
}



RGBTRIPLE **alloc_memory(int Y, int X )
{        
        RGBTRIPLE **temp = new RGBTRIPLE *[ Y ];
	RGBTRIPLE *temp2 = new RGBTRIPLE [ Y * X ];
        memset( temp, 0, sizeof( RGBTRIPLE ) * Y);
        memset( temp2, 0, sizeof( RGBTRIPLE ) * Y * X );

        for( int i = 0; i < Y; i++){
                temp[ i ] = &temp2[i*X];
        }
 
        return temp;
 
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
	RGBTRIPLE *temp;
	temp = a;
	a = b;
	b = temp;
}

