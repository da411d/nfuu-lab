#include <iostream>
#include "DrugStore.h"
#include "Drug.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Ukrainian");

	DrugStore store;
	store.addItem("��������i�", 1500, 5);
	store.addItem("��������", 2500, 10);
	store.addItem("���������", 3500, 11);
	store.print();
	
	try{
		store.list[0] += 3;
		store.list[0] + 1234;

		store.list[1] -= 3;
		store.list[1] + 399;

		store.list[2] -= 7;
		store.list[7] - 1;
	}catch(runtime_error &e){}

	store.print();
	system("pause >> NUL");
}