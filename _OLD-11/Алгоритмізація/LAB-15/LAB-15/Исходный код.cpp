#include <iostream>
#include <time.h>
#include <typeinfo>
using namespace std;
/*
	������ �i���i��� ������i� �������i�, ������������ �i� ��������
	�i�������� ������i �.
*/

template <class T> T** genArray(int, int, int);
template <class T> void printArray(T**, int);
template <class T> int getArraySomething(T**, int);

void main(){
	srand(time(0));
	setlocale(LC_ALL, "Ukrainian");
	cout << "------------- ���� 14 -------------\r\n" 
		 << "--------- ������� �����i� ---------\r\n";
	int size = 5 + rand()%10;
	
	int **int_r = genArray<int>(size, -4, 4);
	printArray<int>(int_r, size);
	cout << "���� ������i� �������i�, ������������ �i� �������� �i��������: " << getArraySomething<int>(int_r, size) << "\r\n";
	cout << "-----------------------------------\r\n\r\n";

	float **float_r = genArray<float>(size, -4, 4);
	printArray<float>(float_r, size);
	cout << "���� ������i� �������i�, ������������ �i� �������� �i��������: " << getArraySomething<float>(float_r, size) << "\r\n";
	cout << "-----------------------------------\r\n\r\n";
	
	bool **bool_r = genArray<bool>(size, 0, 1);
	printArray<bool>(bool_r, size);
	cout << "���� ������i� �������i�, ������������ �i� �������� �i��������: " << getArraySomething<bool>(bool_r, size) << "\r\n";
	cout << "-----------------------------------\r\n\r\n";

	cout << "�i����.";
	system("pause>>NUL");
}



template <class T> T** genArray(int size, int min, int max){
	T **arr;
	arr = new T*[size];
	for(int i=0;i<size;i++){
		arr[i] = new T[size];
	}
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			arr[i][j] = min + rand()%(max-min+1);
		}
	}
	return arr;
}

template <class T> void printArray(T **arr, int size){
	cout << "����� ���� " << typeid(arr[0][0]).name() << "\r\n";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(arr[i][j] >=0)cout << " ";
			cout << arr[i][j] << " ";
		}
		cout << "\r\n";
	}
	cout << "\r\n";
}
template <class T> int getArraySomething(T **arr, int size){
	int count = 0;

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			count += i>j && arr[i][j]>0;
		}
	}
	return count;
}