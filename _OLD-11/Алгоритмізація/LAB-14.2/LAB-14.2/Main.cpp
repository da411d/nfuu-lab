#include <iostream>
#include <string>
using namespace std;

/*
	Скласти програму для викреслювання зі слів тексту всіх букв, що стоять на
	непарних місцях після букви «а».
*/

string str, str2;

void main(){
	getline(cin, str);
	cout << "\r\n";
	for(int i=0;i<str.length(); i++){
		if(i%2 == 1 && str[i-1]=='a')continue;
		str2 += str[i];
	}
	cout << str2;
	system("pause>>nul");
}