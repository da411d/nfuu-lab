#pragma once
class TimeController
{
public:
	TimeController(void);
	~TimeController(void);
	void setTime(int h, int m);
	bool addSecond(void);
	int getHours(void);
	int getMinutes(void);
	int getSeconds(void);

private: 
	int h, m, s;
};