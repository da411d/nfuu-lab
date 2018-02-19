#include <Windows.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
CRITICAL_SECTION cs;

float x = 2.7 * 5;
const int n = 10, m = 5;
float a[n][m], b[n][m];
float _a(float i, float j);
float _b(float i, float j);

DWORD WINAPI thread(LPVOID iNum){
	int i, j;
	/*
		INIT && SORT ARRAY
	*/
	for(j=0; j<m; j++){
		for(i=0; i<n; i++){
			b[i][j] = _b(i, j);
			Sleep(7);
		}
	} 
	sort(*b, *b + m*n);

	/*
		OUTPT
	*/
	EnterCriticalSection(&cs); 
	cout << "/-  B  -/ \r\n";
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cout << b[i][j] << "  " << flush;
			Sleep(7);
		}
		cout << endl;
	} 
	cout << endl;
	LeaveCriticalSection(&cs); 
	return 0;
}

int main(){
	/*
		MAGIC
	*/
	int i, j;
	HANDLE hThread;
	DWORD IDThread;
	InitializeCriticalSection(&cs);
	hThread = CreateThread(NULL, 0, thread, (void*)1, 0, &IDThread);
	if(hThread == NULL)return GetLastError();
	
	/*
		INIT && SORT ARRAY
	*/
	for(j=0; j<m; j++){
		for(i=0; i<n; i++){
			a[i][j] = _a(i, j);
			Sleep(7);
		}
	} 
	sort(*a, *a + m*n);

	/*
		OUTPT
	*/
	EnterCriticalSection(&cs); 
	cout << "/-  A  -/ \r\n";
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cout << a[i][j] << "  " << flush;
			Sleep(7);
		}
		cout << endl;
	} 
	LeaveCriticalSection(&cs);
	getch();
	WaitForSingleObject(hThread, INFINITE);
	return 0;
}



float _a(float i, float j){
	float t = (i-j) / (i + j*j/2);
	return floor(t*100 + 0.5)/100;
}
float _b(float i, float j){
	float t = (i*i - cos(j)) / (x + 1.5 + i*j);
	return floor(t*100 + 0.5)/100;
}