#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

void main(){
	setlocale(0, "");
	srand(time(0));
	const int M = 100;

	cout << " -= LAB #1 =-" << endl;

	/*
		TASK-1
	*/
	cout << " - Завдання 1 -" << endl;
	int countA = 0;
	float p = 0.6;
	for(int i = 0; i < M; i++){
		float a = round((float)rand() / RAND_MAX * 1000) / 1000;
		cout << (i+1 <= 9 ? " " : "") << i + 1 << " | " << a << "\t";
		if(a < p){
			cout << " - подiя А відбулась";
			countA++;
		}
		cout << endl;
	}
	cout << "Кiлькiсть випадання подiї А = " << countA << endl;
	cout << "Ймовiрнiсть = " << (float)countA / M << endl;

	cout << endl << endl << endl << endl << endl;

	/*
		TASK-2
	*/
	cout << " - Завдання 1 -" << endl;

	float	x1 = 0.5,
			x2 = 0.15,
			x3 = 0.15,
			x4 = 2;
	int count_x1 = 0, 
		count_x2 = 0, 
		count_x3 = 0, 
		count_x4 = 0;
	for(int i = 0; i < M; i++){
		float p = rand() % (100)*0.01;
		if(p < x1){
			cout << i << ".\t" << "10" << endl;
			count_x1++;

		}else if(x1 <= p && p < x1 + x2){
			cout << i << ".\t" << "25" << endl;
			count_x2++;

		}else if(x1 + x2 <= p && p < x1 + x2 + x3){
			cout << i << ".\t" << "100" << endl;
			count_x3++;

		}else{
			cout << i << ".\t" << "200" << endl;
			count_x4++;
		}

	}
	cout << "Ймовiрнiсть  випадання 10\t" << (float)count_x1 / M << endl;
	cout << "Ймовiрнiсть випадання 25\t" << (float)count_x2 / M << endl;
	cout << "Ймовiрнiсть випадання 100\t" << (float)count_x3 / M << endl;
	cout << "Ймовiрнiсть випадання 200\t" << (float)count_x4 / M << endl;
	system("pause");

}

