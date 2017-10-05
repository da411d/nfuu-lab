#include <iostream>
#include "Drugs.h"
#include "Drug.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Ukrainian");

	Drugs store;
	store.addItem("Фармазолiн", 1950);
	store.addItem("Реназолін", 2499);
	store.addItem("Назоспрей", 3377);
	
	store.print();

	system("pause >> NUL");
}