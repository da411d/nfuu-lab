#include <iostream>
#include <locale>
#include <time.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;


float _max(float* M, int n){
	vector <float> arr;
	vector <float> :: iterator ma;
	for (int i = 0; i<n; i++){
		arr.push_back(M[i]);
	}
	ma = max_element(arr.begin(), arr.end());
	return *ma;
}

float _min(float* M, int n){
	vector <float> arr;
	vector <float> :: iterator mi;
	for (int i = 0; i<n; i++){
		arr.push_back(M[i]);
	}
	mi = min_element(arr.begin(), arr.end());
	return *mi;
}

float _sum(const float* M, int n){
	float s = 0;
	int ind = 0;

	cout << endl << endl;
	for (int i = n-1; i>=0; i--){
		if (M[i] < 0)
		ind = i;
	}
	s = accumulate(M+0, M+ind, 0);
	return s;
}

void _sub(float* M, int n, int zm1, int zm2){
	vector <float> arr;
	for (int i = 0; i<n; i++){
		if (M[i] >= zm1 && M[i] <= zm2){
			M[i] = 0;
		}
	}
	int counts = 0;
	for (int i = 0; i<n; i++){
		if (M[i] != 0){
			arr.push_back(M[i]);
		}else{
			counts++;
		}
	}
	for (int i = 0; i<counts; i++){
		arr.push_back(0);
	}
	for (int i = 0; i<n; i++){
		if (arr[i] != 0){
			M[i] = arr[i];
		}else{
			M[i] = 0;
		}
	}
	arr.shrink_to_fit();
}


int main(){
	setlocale(LC_ALL, "Ukrainian");
	int n;
	float* arr;
	cout << "Введiть розмiр масиву: "; cin >> n;
	arr = new float[n];

	system("cls");
	cout << "Згенерований масив:\n";


	srand(time(0));
	for (int i = 0; i<n; i++){
		arr[i] = (rand() % 40 - 15);
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "Максимальний елемент: " << _max(arr, n) << endl;
	cout << "Мiнiмальний елемент: " << _min(arr, n) << endl;
	cout << "Сума елементiв до першого вiд'ємного: " << _sum(arr, n) << endl;
	
	cout << endl;

	int a, b;
	cout << "Задайте iнтервал:";
	cout << "a="; cin >> a;
	cout << "b="; cin >> b;
	_sub(arr, n, a, b);

	cout << "Стиснутий масив: " << endl;
	for (int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	_getch();
	return 0;
}