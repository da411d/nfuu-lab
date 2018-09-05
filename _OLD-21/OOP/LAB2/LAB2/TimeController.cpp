#include "TimeController.h"


TimeController::TimeController(void){
	this->h = 0;
	this->m = 0;
	this->s = 0;
}
TimeController::~TimeController(void){}

void TimeController::setTime(int h, int m){
	this->h = h;
	this->m = m;
	this->s = 0;
}

bool TimeController::addSecond(void){
	this->s += 1;
	if(this->s > 59){
		this->s = 0;
		this->m += 1;
		if(this->m > 59){
			this->m = 0;
			this->h += 1;
			if(this->h > 23){
				this->h = 0;
				return true;
			}
		}
	}
	return false;
}

int TimeController::getHours(void){return this->h;}
int TimeController::getMinutes(void){return this->m;}
int TimeController::getSeconds(void){return this->s;}