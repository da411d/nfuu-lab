#include <iostream>
#include "DrugStore.h"
#include "Drug.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Ukrainian");

	DrugStore store;
	store.addItem("Farmazolin", 1500, 5);
	store.addItem("Renazolin", 2500, 10);
	store.addItem("Nazosprei", 3500, 11);
	store.print();
	try{
		store.list[0] += 3;
		store.list[0] + 1234;

		store.list[1] -= 3;
		store.list[1] + 399;

		store.list[2] -= 7;
		store.list[7] - 1;
	}catch(...){}

	store.print();


	int cnt;
	cout << "Пошук за числом: "; cin >> cnt;
	try{
		store.search(cnt).render();
	}catch(Drug){
		cout << "Товар не знайдено!" << endl;
	}

	char name[64];
	cout << "Пошук за назвою: "; cin >> name;
	try{
		store.search(name).render();
	}catch(Drug){
		cout << "Товар не знайдено!" << endl;
	}

	system("pause >> NUL");
}