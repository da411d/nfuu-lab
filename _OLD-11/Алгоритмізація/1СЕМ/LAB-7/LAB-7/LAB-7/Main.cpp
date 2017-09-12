#include <iostream>
#include <conio.h>
#include <windows.h>
#include <math.h>
using namespace std;
int main(){
	setlocale(LC_ALL, "UKrainian");
	float mi1 = 9999999, mi2 = 9999999;
	float alpha, x, a = 3.45, b = 1.62;
	cout << "Ghjuhfvf j,xbktyyz ayrws]? ]] vsyfkmyjuj ljnymjuj nf vsy/ ds.... Та ну блiн..."<<endl<<endl;
	x = 0.1;
	cout << "x" << "\t" << "alpha" << endl;
	cout << "--------------------------------" << endl;
	while(x<=3.1){
		alpha = (1+pow(a, x))/((b-x)*pow(sin(x), 3));
		cout << x << "\t" << alpha << endl;
		if(alpha > 0 && alpha < mi1){
			mi1 = alpha;
		}
		if(alpha < 0 && alpha < mi2){
			mi2 = alpha;
		}
		x+=0.15;
	}
	cout << endl << endl;
	cout << "Найменше додатне число = " << mi1 << endl;
	cout << "Найменше вiд'ємне число = " << mi2 << endl;
	system("pause >> NUL");
	return 0;
}