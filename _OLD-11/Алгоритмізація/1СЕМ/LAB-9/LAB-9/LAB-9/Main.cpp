#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
using namespace std;
float rnd(int i, int a){
	srand(time(0)+rand());
	return i + rand()%(a-i+1);
}
double round(double d, int n){
  return floor((d + 0.5)*pow(10, (float)n))/pow(10, (float)n);
}
void z1(){
	const int w = 6, h = 5;
	float T[w][h];
	cout << "BEFORE:" << endl;
	for(int j = 0;j<h;j++){
		for(int i=0;i<w;i++){
			T[i][j] = rnd(1, 10);
			cout << T[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "AFTER:" << endl;
	for(int j = 0;j<h;j++){
		for(int i=0;i<w;i++){
			T[i][j] = T[i][j]/T[i][h-1];
			cout << round(T[i][j], 2) << "\t";
		}
		cout << endl;
	}
}
void z2(){
	const int n = 4;
	float A[n][n], B[n][n], C[n][n];
	cout << "A:" << endl;
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			A[i][j] = rnd(1, 10);
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "B:" << endl;
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			B[i][j] = rnd(1, 10);
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	cout << "C:" << endl;
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++){
			C[i][j] = A[i][j];
			for(int k = 0;k<n;k++){
				C[i][j] -= B[j][k];
			}
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
}
void main(){
	z1();
	system("pause >> NUL");cout << endl<<endl;
	z2();
	system("pause >> NUL");
}