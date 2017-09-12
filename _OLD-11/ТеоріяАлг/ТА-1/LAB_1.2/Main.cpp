/*
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

int rnd(int a, int b){srand(time(0)+rand());return a + rand()%(b-a+1);}
void pause(){system("pause>>NUL");}
void gen();
void search();
void list();
float searchMin(float* mas, int n);
float f(int i);
const int n = 10;
float arr[n];
float mi, ma;
void main(){
	gen();
	cout << "Before: \r\n";
	list();
	search();
	for(int i=0;i<n;i++){
		if(arr[i] == mi){
			cout << "Min: arr[" << i << "] = " << arr[i] << "\r\n";
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i] == ma){
			cout << "Max: arr[" << i << "] = " << arr[i] << "\r\n";
		}
	}
	cout << searchMin(arr, n);
	pause();
	return;
}
float f(int i){return sin(2.*i)/(i*i+4)+1;}
void gen(){
	for(int i=0;i<n;i++){
		arr[i] = f(i);
	}
}
void search(){
	mi = arr[0];
	ma = arr[0];
	for(int i=1;i<n;i++){
		if(mi > arr[i]){
			mi = arr[i];
		}
		if(ma < arr[i]){
			ma = arr[i];
		}
	}
}
float searchMin(float* mas, int n){
	mi = mas[0];
	for(int i=1;i<n;i++){
		if(mi > mas[i]){
			mi = mas[i];
		}
	}
	return mi;
}
void list(){
	for(int i=0;i<n;i++){
		cout << arr[i] << ", ";
	}
	cout << "\b\b  \r\n";
}


*/

///*
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

const int _N = 1000;
int rnd(int, int);
void pause();
void step1();
void step2();

int arr[_N], needle = 0;
void main(){
	step1();
	cout << "I wanna find number " << needle << "\r\n";
	step2();
	pause();
}
void step1(){
	arr[0] = rnd(5, 15);
	for(int i=1;i<_N;i++){
		arr[i] = rnd(arr[i-1]+rnd(1, 5), arr[i-1]+rnd(5, 10));
	}

	for(int i=1;i<_N;i++){
		cout << arr[i] << ", ";
	}
	cout << "\b\b \r\n";
	needle = arr[rnd(0, _N-1)];
}
void step2(){
	int playhead = 0,
		step = _N,
		direction = 1;
	while(!0){
		step = floor(step/2. + .5);
		playhead += step*direction;
		if(arr[playhead] > needle){
			cout << arr[playhead] << " > " << needle << "\r\n";
			direction = -1;
		}else if(arr[playhead] < needle){
			cout << arr[playhead] << " < " << needle << "\r\n";
			direction = 1;
		}else{
			cout << arr[playhead] << " = " << needle << "\r\n";
			return;
		}
	}
}

void pause(){
	system("pause>>NUL");
}
int rnd(int i, int a){
	srand(time(0)+rand());
	return i + rand()%(a-i-1);
}
//*/