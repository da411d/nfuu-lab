#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

const int _N = 4;
double arr[_N][_N];
double f(int, int);

void main(){
	srand(time(0));
	for(int i=0;i<_N;i++){
		for(int j=0; j<_N; j++){
			arr[i][j] = f(i, j);
			cout << arr[i][j] << "  ";
		}
		cout << "\r\n";
	}
	cout << "\r\n-------------------------\r\n";
	for(int i=0;i<_N;i++){
		double t = arr[i][0];
		arr[i][0] = arr[i][2];
		arr[i][2] = t;
	}
	for(int i=0;i<_N;i++){
		for(int j=0; j<_N; j++){
			cout << arr[i][j] << "  ";
		}
		cout << "\r\n";
	}
	system("pause>>NUL");
}
double f(int i, int j){
	return pow(i*1., 3)/pow(cos(i*1.), 2)*pow(pow(j, 5.), 1./3); 
}