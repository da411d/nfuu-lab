#include <iostream>
#include <math.h>
using namespace std;

float f(int);
const int _N = 10;
float arr[_N], lg, lgcnt;

void main(){
	for(int i=0; i<_N; i++){
		arr[i] = f(i);
		cout << arr[i] << "\r\n";
		if(arr[i]>0){
			lg += log10(arr[i]);
			lgcnt++;
		}
	}
	cout << "log10: " << (lg/lgcnt);
	system("pause>>NUL");
}

float f(int i){
	return i*i - 5*i*i*i + pow(cos(sqrt(i*i + 5.)), 2);
}