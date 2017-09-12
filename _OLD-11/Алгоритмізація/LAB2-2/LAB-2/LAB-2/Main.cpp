#define _n 7
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int rnd(int i, int a){
	srand(time(0)+rand());
	return i + rand()%(a-i-1);
}
void pause(){system("pause>>NUL");}
bool hasMinus(int a[_n]);
int sum(int a[_n]);
int getDiag(int i);
void displayDiag(int i);
void color(int);

int arr[_n][_n];
int d[_n];
void main(){
	setlocale(LC_ALL, "Ukrainian");
	for(int i=0;i<_n;i++){
		for(int j=0;j<_n;j++){
			arr[i][j] = rnd(0,10)?rnd(0,9):rnd(-9,0);
		}
	}
	
	for(int j=0;j<_n;j++){
		for(int i=0;i<_n;i++){
 			color(9 + (i-j+_n*2)%7);
			if(arr[i][j]>=0)cout<<" ";
			cout << arr[i][j] << "  ";
		}
 		color(0x07);
		cout << "\r\n";
	}

	for(int i=0;i<_n;i++)cout<<"----";cout << "\r\n";
	for(int i=0;i<_n;i++){
		if(!hasMinus(arr[i])){
			int s = sum(arr[i]);
			if(s<10)cout << " ";
			cout << s;
		}else{
			cout << "  ";
		}
		cout << "  ";
	}
	cout << "<---- То є суми елементiв в тих стовпцях, якi не мiстять вiд’ємних елементiв\r\n";

	for(int i=0;i<_n;i++)cout<<"----";cout << "\r\n";
	int max = getDiag(0), maxindex = 0;
	for(int i=_n*2 - 1;i>0;i--){
		if(max < getDiag(i)){
			max=getDiag(i);
			maxindex=i;
		}
	}
	for(int i=_n*2 - 1;i>0;i--){
 			color(9 + i%7);
			displayDiag(i);
			if(i == maxindex){
				cout << " <----- Оце максимум";
			}
			cout << "\r\n";
	}
	pause();
}

bool hasMinus(int a[_n]){
	for(int i=0;i<_n;i++){
		if(a[i]<0)return true;
	}
	return false;
}
int sum(int a[_n]){
	int s = 0;
	for(int i=0;i<_n;i++){
		s += a[i];
	}
	return s;
}



int getDiag(int o){
	int s = 0;
	for(int j=0;j<_n;j++){
		for(int i=0;i<_n;i++){
			if(i+_n-o==j){
				s += arr[i][j];
			}
		}
	}
	return s;
}
void displayDiag(int o){
	int s = 0;
	
	for(int t=0;t<o-_n;t++)cout << "    ";
	for(int j=0;j<_n;j++){
		for(int i=0;i<_n;i++){
			if(i+_n-o==j){
				if(arr[i][j] >= 0)cout << " ";
				cout << arr[i][j] << "  ";
				s += arr[i][j];
			}
		}
	}
	for(int t=0;t<_n-o;t++)cout << "    ";
	cout << " | ";
	if(s<=10 || s>=-10)cout << " ";
	if(s>0)cout << " ";
	cout << s;
}


void color(int a = 0x07){
 	HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );
 	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
	CONSOLE_SCREEN_BUFFER_INFO csbi;
 	GetConsoleScreenBufferInfo( hstdout, &csbi );
 	SetConsoleTextAttribute(hstdout, a);
}