#include "Solution.h"
#include "iostream"
#include "Math.h"
using namespace std;

// Обчислення функції b[x,y,z]
void Solution::Fn_b(double x, double y, double z){
        double b1 = (x*x) + (z*z)/pow(tan(pow(fabs(x), 0.3)), 2);
        double b2 = 3 + x + (y*y)/fa(2) + (z*z*z)/fa(3);
        double b3 = pow(log(pow(fabs(y/z), 1./3)), 1./3);
		cout << b1 << " " << b2 << " " << b3;
        b = b1 / b2 + b3;
}
// Обчислення функції a[x,y,z,b]
void Solution::Fn_a(double x, double y, double z){
        double a1 = 2*cos(fabs(pow(x, 1./3))) - (x*x)/6;
        double a2 = z/b + pow(sin(y+z), 2);
        double a3 = pow(log(pow(fabs(z), 0.6)), 2);
        a = a1 / a2 + a3;
}
double Solution::fa(int n){
        double f=1;
        if(n > 1)for(int i=2; i<=n; i++)f*=i;
        return f;
}
double Solution::round(double x, int n){
        return floor(x*pow(10, n)+0.5)/pow(10, n);
}
