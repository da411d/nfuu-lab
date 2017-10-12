#include "Drug.h"
#include "iostream"
using namespace std;


Drug::Drug(void){
	this->name = "Undefined";
	this->price = 0;
	this->count = 0;
}
Drug::Drug(char* n){
	this->name = n;
	this->price = 0;
	this->count = 0;
}
Drug::Drug(char* n, int p){
	this->name = n;
	this->price = p;
	this->count = 0;
}
Drug::Drug(char* n, int p, int c){
	this->name = n;
	this->price = p;
	this->count = c;
}
Drug::~Drug(void){}

char* Drug::getName(){
	return name;
}
int Drug::getCount(){
	return count;
}
int Drug::getPrice(){
	return price;
}
void Drug::render(void){
	int coins = price % 100;
	int uah = (price-coins)/100;
	cout << name << "  |  " << uah << "." << coins << "  |  " << count << "רע." << endl;
}


Drug Drug::operator+=(int n){
	try{
		this->count += n;
	}catch(int e){}
   	return *this;
}
Drug Drug::operator-=(int n){
	try{
		this->count -= n;
	}catch(int e){}
   	return *this;
}

Drug Drug::operator+(int n){
	try{
		this->price += n;
	}catch(int e){}
   	return *this;
}
Drug Drug::operator-(int n){
	try{
		this->price -= n;
	}catch(int e){}
   	return *this;
}