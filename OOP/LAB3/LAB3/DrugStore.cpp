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
	cout << "—ума: " << uah << "." << coins << endl << endl;
}

Drug DrugStore::search(int val){return search(val, 0);}
Drug DrugStore::search(int val, int offset = 0){
	for(int i = offset; i < current; i++){
		if(list[i].getCount() == val || list[i].getPrice() == val){
			return list[i];
		}
	}
	throw list[0];
	return list[0];
}

Drug DrugStore::search(char* val){return search(val, 0);}
Drug DrugStore::search(char* val, int offset = 0){
	for(int i = offset; i < current; i++){
		int cmp = strcmp(list[i].getName(), val);
		if(cmp == 0){
			return list[i];
		}
	}
	throw list[0];
	return list[0];
}