#include "Drugs.h"

Drugs::Drugs(void){
	current = 0;
}
Drugs::~Drugs(void){}

int Drugs::getSum(){
	int sum = 0;
	for(int i=0; i<current; i++){
		sum += list[i]->getPrice()*list[i]->getCount();
	}
	return sum;
}
void Drugs::addItem(char* n){
	Drug temp(n);
	list[current++] = &temp;
}
void Drugs::addItem(char* n, int p){
	Drug temp(n, p);
	list[current++] = &temp;
}
//void Drugs::getItem(int n, Drug &target){
//	if(n < 0)n=0;
//	if(n > current)n = current;
//	target = list[n];
//}

void Drugs::print(){
	for(int i=0; i<current; i++){
		list[i]->render();
	}
	cout << "Сума: " << getSum() << endl;
}