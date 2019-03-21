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
	cout << " - �������� 1 -" << endl;
	int countA = 0;
	float p = 0.6;
	for(int i = 0; i < M; i++){
		float a = round((float)rand() / RAND_MAX * 1000) / 1000;
		cout << (i + 1 <= 9 ? " " : "") << (i + 1 <= 99 ? " " : "") << i + 1 << " | " << a << "\t";
		if(a < p){
			cout << " - ���i� � �i�������";
			countA++;
		}
		cout << endl;
	}
	cout << "�i���i��� ��������� ���i� � = " << countA << endl;
	cout << "����i��i��� = " << (float)countA / M << endl;

	cout << endl << endl << endl << endl << endl;

	/*
		TASK-2
	*/
	cout << " - �������� 2 -" << endl;
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

		cout << (i + 1 <= 9 ? " " : "") << (i + 1 <= 99 ? " " : "") << i + 1 << " | ";
		if(p < x1){
			cout << "X1";
			count_x1++;

		}else if(p < x1 + x2){
			cout << "  X2";
			count_x2++;

		}else if(p < x1 + x2 + x3){
			cout << "    X3";
			count_x3++;

		}else{
			cout << "      X4";
			count_x4++;
		}
		cout << endl;
	}

	cout << "����i��i��� ��������� X1 - " << (float)count_x1 / M << endl;
	cout << "����i��i��� ��������� X2 - " << (float)count_x2 / M << endl;
	cout << "����i��i��� ��������� X3 - " << (float)count_x3 / M << endl;
	cout << "����i��i��� ��������� X4 - " << (float)count_x4 / M << endl;
	system("pause>NUL");
}

