#include <cstdio>
#include "BMI.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(){
    BMI bb;
    double bmi;
    string cate;

    double height,mass;

    ifstream inFile("file.in",ios::in);
    if(!inFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }

    ofstream outFile("file.out",ios::out);
    if(!outFile){
        cerr << "Failed opening" << endl;
        exit(1);
    }

    while(inFile >> height >> mass && (height||mass) ){
        bb.set(height,mass);
        bmi=bb.acc();
        cate=bb.category();
        outFile<< fixed << setprecision(2) <<bmi<<"\t"<<cate<<endl;
    }

    return 0;
}
