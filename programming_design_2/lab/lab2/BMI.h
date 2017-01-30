#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

class BMI{
    public:
        BMI();
        void set(double a,double b);
        double get_h();
        double get_m();
        double acc();
        string category();
    private:
        double height;
        double mass;
        double bmi;
};
