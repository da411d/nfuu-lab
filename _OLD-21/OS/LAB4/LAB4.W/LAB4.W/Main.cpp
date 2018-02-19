#pragma hdrstop
#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;

#define _FILENAME_ "D:\\_PROJECTS\\_LAB\\OS\\LAB4\\369d125b-3a99-4752-b007-7883e1a26c66.txt" 

void main(){
	HANDLE h = CreateMutex(NULL, TRUE, L"WriteData");
	ofstream f(_FILENAME_);
	cout << "Writing to file:" << endl;
	for(int i=256; i<4096; ++i){
		cout << i << endl;
		f << i << " ";
	}
	system("pause");
	f.close();
	ReleaseMutex(h);
	CloseHandle(h);
}