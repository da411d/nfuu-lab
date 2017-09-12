#define _n 14
#include <iostream>
#include <math.h>
using namespace std;

float f(float);
void sort1(float* ar, int n);
void sort2(float* ar, int n);

float arr[_n], arr1[_n], arr2[_n],
	x_s = 0.15,
	x_f = 1.5, 
	s = 0.1;

void main(){
	setlocale(LC_ALL, "Ukrainian");
	int k = 0;
	cout << "----------------\r\nВихiдний масив\r\n----------------\r\n";
	for(float t=x_s;t<x_f;t+=s){
		arr[k] = f(t);
		arr1[k] = arr[k];
		arr2[k] = arr[k];
		cout << arr[k] << "\r\n";
		k++;
	}

	cout << "\r\n\r\n----------------\r\nСортування вибором\r\n----------------\r\n";
	sort1(arr1, _n);
	for(int i=0; i<_n; i++){
		cout << arr1[i] << "\r\n";
	}

	cout << "\r\n\r\n----------------\r\nСортування обмiном\r\n----------------\r\n";
	sort2(arr2, _n);
	for(int i=0; i<_n; i++){
		cout << arr2[i] << "\r\n";
	}

	system("pause>>NUL");
}

float f(float x){
	float a, b = 0.86;
	if(x < 0.55){
		a = 0.001;
	}else if(x == 0.55){
		a = 1.25;
	}else if(x > 0.55){
		a = 2.55;
	}
	return pow(pow(a, 3) + pow(x, 3), 1/3) / (pow(tan(b*x), 3) + 1.6);
}

/*
Сортування вибором
*/
void sort1(float* ar, int n){
	for(int i=0;i<n;i++){
		float min = ar[i];
		int min_i = i;
		for(int j=i+1;j<n;j++){
			if(ar[j] && min > ar[j]){
				min = ar[j];
				min_i = j;
			}
		}
		ar[min_i] = ar[i];
		ar[i] = min;
	}
}

/*
Сортування обміном (бульками)
*/
void sort2(float* ar, int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(ar[j] > ar[j+1]){
				float t = ar[j+1];
				ar[j+1] = ar[j];
				ar[j] = t;
			}
		}
	}
}