#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "\n----------------- Лабораторна робота №2.5 ---------------------------\n\n";

	float y, a, b, f, f1, f2;
	
	cout << "Введiть значення:" << endl;
	
	cout << "\tlambda=";
		cin >> y;
		if(y<0.15 || y>1.5){
			system("cls");
			cout << "Помилка!!!" << endl;
				if(y<0.15){
					cout << "Лямбда не може бути меншою за 0.15" << endl;
				}else{
					cout << "Лямбда не може бути бiльшою за 1.5" << endl;
				}
			system("pause");
			return -1;
		}

	cout << "\ta=";
		cin >> a;

	cout << "\tb=";
		cin >> b;
		
	f1 = pow(a,3) + pow(y,3);
	f1 = pow(f1, 1/3);

	f2 = tan(b*y);
	f2 = pow(f2, 3);
	f2 += 1.6;

	f = f1/f2;

	cout<<"\nРезультат виконання обчислення:\n\tf(x, y, z) = "<<f<<endl;
	cout<<"--------------------------------------------------------------------- \n";
	system("pause");
	return 0;
}