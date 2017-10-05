#include "DrugStore.h"

DrugStore::DrugStore(void){
	this->current = 0;
}
DrugStore::~DrugStore(void){}

int DrugStore::getSum(){
	int sum = 0;
	for(int i=0; i<current; i++){
		sum += list[i].getPrice()*list[i].getCount();
	}
	return sum;
}
void DrugStore::addItem(char* n){
	Drug temp(n);
	list[current++] = temp;
}
void DrugStore::addItem(char* n, int p){
	Drug temp(n, p);
	list[current++] = temp;
}
void DrugStore::addItem(char* n, int p, int c){
	Drug temp(n, p, c);
	list[current++] = temp;
}

void DrugStore::print(){
	for(int i=0; i<current; i++){
		list[i].render();
	}
	int sum = getSum();
	int coins = sum % 100;
	int uah = (sum-coins)/100;
	cout << "Сума: " << uah << "." << coins << endl << endl;
}