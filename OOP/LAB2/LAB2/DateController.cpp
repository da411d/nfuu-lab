#include "DateController.h"


DateController::DateController(void){
	this->y = 2017;
	this->m = 9;
	this->d = 27;
}
DateController::~DateController(void){}

void DateController::setDate(int y, int m, int d){
	this->y = y;
	this->m = m;
	this->d = d;
}

void DateController::addDay(void){
	this->d += 1;
	if(this->d > 30){
		this->d = 1;
		this->m += 1;
		if(this->m > 12){
			this->m = 1;
			this->y += 1;
		}
	}
}

int DateController::getYear(void){return this->y;}
int DateController::getMonth(void){return this->m;}
int DateController::getDay(void){return this->d;}