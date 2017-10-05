#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;

const int _INIT_SIZE = 2048;
int _ARRAY[_INIT_SIZE];
int _SIZE = 0;

DWORD WINAPI worker(LPVOID iNum){
	float sum = 0;
	for(int i=0; i<_SIZE; i++){
		if(_ARRAY[i]%2 != 0){
			sum += _ARRAY[i];
		}
		Sleep(12);
	}
	cout << "worker: Сума всiх непарних елементiв: " << sum << endl;
	return 0;
}

int main (){
	setlocale(LC_ALL, "Ukrainian");
	HANDLE hThread;
	DWORD IDThread;
	cout << "Введи розмiр масиву: ";
	cin >> _SIZE;
	cout << "Елеенти масива:" << endl;
	srand(time(0));
	int sum = 0;
	for(int i=0; i<_SIZE; i++){
		_ARRAY[i] = rand()%50 - 25;
		sum += _ARRAY[i];

		if(_ARRAY[i]>=0)cout<<" ";
		if(_ARRAY[i]>-10 && _ARRAY[i]<10)cout<<" ";
		cout << _ARRAY[i];
		if(i!=_SIZE-1)cout << ", ";
		if(i>0 && i%20 == 19){
			cout << endl;
		}
	}
	cout << endl;

	hThread = CreateThread(NULL, 0, worker, (void*)1, 0, &IDThread);

	int max = _ARRAY[0],
		min = _ARRAY[0];

	for(int i=0; i<_SIZE; i++){
		if (max < _ARRAY[i]){
			max = _ARRAY[i];
			Sleep(7);
		}
		if (min > _ARRAY[i]){ 
			min = _ARRAY[i];
			Sleep(7);
		}
	}
	cout<<"main: Максимальний елемент масиву: " << max << endl;
	cout<<"main: Мiнiмальний елемент масиву: " << min << endl;

	WaitForSingleObject(hThread, INFINITE);

	cout << "main: Елементи, бiльшi за середнє значення: " << endl;
	float mid = sum / _SIZE;
	int iter = 0;
	for(int i=0; i<_SIZE; i++){
		if(_ARRAY[i] > mid){
			if(_ARRAY[i]>=0)cout<<" ";
			if(_ARRAY[i]>-10 && _ARRAY[i]<10)cout<<" ";
			cout << _ARRAY[i] << ", ";
			if(iter>0 && (iter+1)%20 == 0){
				cout << endl;
			}
			iter++;
		}
	}
	cout << "\b\b  " << endl;
	CloseHandle(hThread);
	system("pause >> NUL");
	return 0;
}
