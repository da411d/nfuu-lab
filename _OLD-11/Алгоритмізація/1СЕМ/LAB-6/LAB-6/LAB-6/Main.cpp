#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
using namespace std;

void ex1(){
	cout << endl;
	cout << "         завдання 1          " << endl;
	cout << "---- Табулювання функції ----" << endl;

	float x_p = 0,
	x_k = 0,
	dx = 0;

	const float a = 17.3;
	const float b = 0.36;

	float y = 0;

	cout << "Введіть початок проміжку >";
	cin >> x_p;

	cout << "Введіть кінецть проміжку >";
	cin >> x_k;

	cout << "Введіть крок табуляції >";
	cin >> dx;

	
	if( (x_k-x_p)/dx > 10000){
		system("color C");
		cout << "Час виконання більший за 10 секунд!"<<endl;
		cout << "Все одно продовжити? (y/n)";
		char t;
		cin >> t;
		if(t !='Y' && t!='y' && t !='Н' && t!='н'){
			return;
		}
		system("color 7");
	}

	cout << "\t\tг-------+---------------+"<<endl;
	cout << "\t\t| x     | y             |"<<endl;
	cout << "\t\tг-------+---------------+"<<endl;

	for(float x = x_p;x<=x_k;x+=dx){
		y = (pow(exp(a*x), 1/3) + b)/(0.25*pow(log(a*x), 2));
		cout << "\t\t| "<< x << "\t| "<< y << "\t|"<<endl;
		cout << "\t\t|-------+---------------|"<<endl;
	}
}

void ex2(){
	cout << "Обчислення суми і добутку" << endl;

	int n = 0;
	cout << "Введіть значення n >";
	cin >> n;
	float sum = 0, 
		dob = 1;

	for(float k=1;k<=n;k+=1){
		sum += (k+1)/(k+2);
		dob *= (k+1)/(k+2);
	}
	cout << endl << "Результат обчислень:" << endl;
	cout <<  "\tСума :" << sum << endl;
	cout <<  "\tДобуток :" << dob << endl;
}



int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "---------- Лаба 6 -----------" << endl;
	short a = 0;
	cout << "Введи номер підзавдання (1..2): ";
	cin >> a; 
	(a==1)?(ex1()):((a==2)?(ex2()):(main()));

	system("pause");
	return -0;
}