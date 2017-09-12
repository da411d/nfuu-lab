#include <iostream>
#include <string.h>
using namespace std;
bool isId(char *);
const int maxlen = 256;
char str[maxlen];

void main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "Ââåäè òåêñò, ñìåðòíèé!\r\n";
	gets(str);
	cout << "--------------------\r\nÇÀÂÄÀÍÍß 1\r\n--------------------\r\n";
	if(isId(str)){
		cout << "Òàê, öå iäåíòèôiêàòîð";
	}else{
		cout << "Íi, öå íå iäåíòèôiêàòîð";
	}
	cout << "\r\n\r\n--------------------\r\nÇÀÂÄÀÍÍß 2\r\n--------------------\r\n";
	int i=0;
	char * pch = strtok(str, " .,-");
	while (pch != NULL){
		if(i++%2 == 0){
			reverse( pch, &pch[ strlen( pch ) ] );
			cout << pch << " ";
		}
		pch = strtok(NULL, " .,-");
	}
	system("pause>>NUL");
}
bool isId(char *string){
	for(int i=0;string[i];i++){
		if(!isalpha(string[i]) && !isdigit(string[i])){
			return false;
		}
	}
	if(isalpha(string[0])){
		return true;
	}
	return false;
}

