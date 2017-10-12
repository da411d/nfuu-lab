#include <Windows.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
CRITICAL_SECTION cs;
DWORD WINAPI thread(LPVOID iNum){
	float y;
	int i, j;
	EnterCriticalSection(&cs); 
	for(j=0; j<10; j++){
		for(i=0; i<10; i++){
			cout << "i"<<j << " " << flush;
			Sleep(7);
		}
		cout << endl;
	}
	LeaveCriticalSection(&cs); 
	return 0;
}

int main(){
	int i, j;
	float x;
	HANDLE hThread;
	DWORD IDThread;
	InitializeCriticalSection(&cs);
	hThread = CreateThread(NULL, 0, thread, (void*)1, 0, &IDThread);
	if(hThread == NULL){
		return GetLastError();
	}
	
	
	EnterCriticalSection(&cs); 
	for(j=0; j<10; j++){
		for(i=0; i<10; i++){
			cout << "j"<<j << " " << flush;
			Sleep(7);
		}
		cout << endl;
	} 
	LeaveCriticalSection(&cs);
	getch();
	WaitForSingleObject(hThread, INFINITE);
}