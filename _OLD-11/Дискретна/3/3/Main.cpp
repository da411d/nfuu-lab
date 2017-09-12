#include <iostream>
#include <math.h>
using namespace std;

float f(int);
float factorial(int);

const int _N = 10;
const float x = 1.25;
float A[_N];
int start = -1;

void main(){
	for(int i=0;i<_N;i++){
		A[i] = f(i+1);
		if(A[i]>=0 && start == -1){
			start = i;
		}
		cout << A[i] << "\r\n";
	}
	cout << "\r\n\r\n";
	for(int i=start;i<_N-1;i++){
		for(int j = start;j<_N-i-1;j++){
			if(A[j] > A[j+1]){
				float t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
	for(int i=0;i<_N;i++){
		cout << A[i] << "\r\n";
	}
	system("pause>>NUL");
}
float f(int i){
	return pow(log(pow(x+1, 2)), 3)/(factorial(i)-i+3) - pow(i, 1/x);
}

float factorial(int a){
	int t = 1;
	for(int i=1;i<=a;i++){
		t*= i;
	}
	return t;
}
