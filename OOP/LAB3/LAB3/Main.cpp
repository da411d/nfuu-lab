#include <iostream>
#include "Drugs.h"
#include "Drug.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Ukrainian");

	Drugs store;
	store.addItem("��������i�", 1950);
	store.addItem("��������", 2499);
	store.addItem("���������", 3377);
	
	store.print();

	system("pause >> NUL");
}