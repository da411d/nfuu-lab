#include <iostream>
#include <math.h>
using namespace std;

const int n=3;
bool R[n][n]={
		{1,1,0},
		{0,0,1},
		{1,1,1}
	}, 
	S[n][n]={
		{1,0,1},
		{0,0,1},
		{0,1,0}
	}, 
	a[n][n], 
	b[n][n], 
	c[n][n], 
	d[n][n], 
	e[n][n], 
	f[n][n]={
		{1,0,1},
		{0,1,0},
		{1,1,1}
	};

int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "Вiдношення R:" << endl;
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cout << R[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "Вiдношення S:" << endl;

	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cout << S[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "R^-1:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			a[i][j]=R[j][i];
			cout << a[i][j]  << " ";
		}
		cout << endl;
	}

	cout << endl << "Об’єднання:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			b[i][j] = R[i][j] || S[i][j];
			cout << b[i][j]  << " ";
		}
		cout << endl;
	}
	cout << endl << "Перетин:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			c[i][j] = R[i][j] && S[i][j];
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "Додавання за модулем 2:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			d[i][j] = R[i][j] ^ S[i][j];
			cout << d[i][j]  << " ";
		}
		cout << endl;
	}

	cout << endl << "Рiзниця:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			e[i][j] = (R[i][j]+S[i][j]==1) ? S[i][j] : 0;
			cout << e[i][j]  << " ";
		}
		cout << endl;
	}

	cout << endl << "Композицiя:" << endl;
	for(int i=0; i < n;++ i){
		for(int j=0; j < n;++ j){
			cout << f[i][j]  << " ";
		}
		cout << endl;
	}
	system("pause>>NUL");
	return 0;
}