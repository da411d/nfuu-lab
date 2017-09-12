#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main(){
	srand(time(0)+rand());
	int size = 7+rand()%5;
	setlocale(LC_ALL, "Ukrainian");

	/*
		Завдання 1
		Створити динамічний одновимірний масив Т. Знайти різницю між максимальним та мінімальним елементом.
	*/
	cout << "Завдання 1\r\nМасив: ";
	int *T;
	T = new int[size];
	T[0] = rand()%12;
	int mi=T[0], ma=T[0];
	cout << T[0] << ", ";
	for(int i=1; i<size; i++){
		T[i] = rand()%12+rand()%12;
		cout << T[i] << ", ";
		if(T[i] < mi){mi = T[i];}
		if(T[i] > ma){ma = T[i];}
	}
	cout << "\b\b \r\nРезультат: " << ma-mi;
	system("pause>>NUL");
	
	/*
		Завдання 2
		Створити динамічний двовимірний масив К. Знайти добуток кожного рядка масиву.
	*/
	cout << "\r\n\r\nЗавдання 2\r\n";
	int **K;

	K = new int*[size];
	for(int i=0;i<size;i++){
		K[i] = new int[size];
	}
	
	for(int i=0; i<size; i++){
		long dob = 1;
		for(int j=0; j<size; j++){
			K[i][j] = 1 + rand()%10;
			if(K[i][j]<10)cout<<" ";
			cout << K[i][j] << ", ";
			dob *= K[i][j]*1L;
		}

		cout <<"\b\b  |  "<< dob << "\r\n";
	}
	system("pause>>NUL");
}