#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;

#define _FILENAME_ "D:\\_PROJECTS\\_LAB\\OS\\LAB4\\369d125b-3a99-4752-b007-7883e1a26c66.txt" 

void main(){
	HANDLE h = CreateMutex(NULL, TRUE, L"WriteData");
	cout << "Please Wait..." << endl;
	WaitForSingleObject(h, INFINITE);

	ifstream f(_FILENAME_);
	char buffer[100];
	f >> buffer;
	cout << "Read Data: " << buffer << endl;
	system("pause");
	f.close();
	CloseHandle(h);
}