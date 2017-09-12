#include <iostream>
#include <math.h>
using namespace std;

void pause(){system("pause>>NUL");}
float f(int);
void init();
void gen();
void list();
void get();

const int n = 10;
float arr[n];
float ser = 1;

void main(){
	init();
	gen();
	list();
	get();
	cout << "\r\n--------------------\r\nСереднє геометричне: "<<ser<<"\r\n--------------------\r\n";
	pause();
}
float f(int i){
	return (float)(
		(i+6)/(2*pow(sin(i+3.), 3))
	);
}
void init(){
	setlocale(LC_ALL, "Ukrainian");
	system("color a");
}
void gen(){
	for(int i=0;i<n;i++){
		arr[i] = f(i);
	}
}
void list(){
	for(int i=0;i<n;i++){
		cout << "> " << arr[i] << "\r\n";
	}
}
void get(){
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			ser *= arr[i];
			cnt++;
		}
	}
	ser = (float)pow((float)ser, (float)1/cnt);
}