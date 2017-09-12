#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
/*
	Напишіть програму, яка визначає реальну заробітну плату, якщо відомі
	такі показники: оклад, податок на доходи фізичних осіб - 13%, збір до Пенсійного
	фонду - 2%, збір до фонду соціального страхування - 1%. Передбачити можливість
	вводу розміру окладу користувачем.
*/
float c(float o){
	return o*(100 - 13 - 2 - 1)/100;
}
void main(){
	setlocale(LC_ALL, "Ukrainian");
	float o;
	cout << "Введи оклад: ";
	cin >> o;
	cout << "Ти получиш " << c(o);
	system("pause>>NUL");
}












/*
float S(float a){
	return sqrt(3*a*a);
}
int rnd(int i=0, int a=1){
	srand(time(0)+rand());
	return rand()%(a-i+1)+i;
}
const int _n = 15;
float arr[_n];
void main(){
	for(int i=0; i<_n; i++){
		arr[i] = i*5 + rnd(0, 5);
		cout << "S(" << arr[i] << ") = " << S(arr[i]) << endl;
	}
	system("pause>>NUL");
}
*/