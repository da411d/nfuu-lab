#pragma once
ref class Solution{
	double a, b;     
public:
       Solution() {a=1; b=1;}
        void Fn_b(double x, double y, double z); // Обчислення функції b[x,y,z]
        void Fn_a(double x, double y, double z);        // Обчислення функції a[x,y,z,b]
        double fa(int n);        // Обчислення факторіалу
        double geta() {return a;}
        double getb() {return b;}
		double round(double, int);
};
