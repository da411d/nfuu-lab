#include "DigitalClock.h"
#include <iostream>
#include <windows.h>

DigitalClock::DigitalClock(void){
	this->stopped = true;
}
DigitalClock::~DigitalClock(void){}

void DigitalClock::start(void){
	this->stopped = false;
	while(!this->stopped){
		this->process();
		Sleep(1000);
	}
}
void DigitalClock::process(void){
	bool needAddDay = this->time.addSecond();
	if(needAddDay){
		this->date.addDay();
	}
	display.render(this->date, this->time);
	if(
		this->time.getHours() == this->alarmH &&
		this->time.getMinutes() == this->alarmM
		){
		this->alarm();
	}
}

void DigitalClock::alarm(void){
	system("color cf");
	Beep(1400, 10);
}

void DigitalClock::setTime(int h, int m){
	this->time.setTime(h, m);
}
void DigitalClock::setDate(int y, int m, int d){
	this->date.setDate(y, m, d);
}
void DigitalClock::setAlarm(int h, int m){
	this->alarmH = h;
	this->alarmM = m;
}