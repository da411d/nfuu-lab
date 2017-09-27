#pragma once
#include "TimeController.h"
#include "DateController.h"
#include "Display.h"
class DigitalClock
{
public:
	DigitalClock(void);
	~DigitalClock(void);
	void start(void);
	void process(void);
	void alarm(void);
	void setTime(int h, int m);
	void setDate(int y, int m, int d);
	void setAlarm(int h, int m);

private:
	TimeController time;
	DateController date;
	Display display;
	int alarmH, alarmM;
	bool stopped;
};