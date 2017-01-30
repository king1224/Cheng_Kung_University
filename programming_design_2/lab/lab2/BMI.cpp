#include "BMI.h"
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

BMI::BMI(){
    height=mass=bmi=0.0;
}

void  BMI::set(double a,double b){
    height=a;
    mass=b;
}

double BMI::get_h(){
    return height;
}

double BMI::get_m(){
    return mass;
}

double BMI::acc(){
    bmi=100*100*get_m()/get_h()/get_h();
    return bmi;
}

string BMI::category(){
    string cate;
    if(bmi<15)
        cate="Very severely underweight";
    else if(bmi<16)
        cate="Severely underweight";
    else if(bmi<18.5)
        cate="Underweight";
    else if(bmi<25)
        cate="Normal";
    else if(bmi<30)
        cate="Overweight";
    else if(bmi<35)
        cate="Obese Class I (Moderately obese)";
    else if(bmi<40)
        cate="Obese Class II (Severely obese)";
    else
        cate="Obese Class III (Very severely obese)";
    return cate;
}
