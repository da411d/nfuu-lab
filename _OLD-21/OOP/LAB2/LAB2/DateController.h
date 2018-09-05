#pragma once
class DateController
{
public:
	DateController(void);
	~DateController(void);
	void setDate(int y, int m, int d);
	void addDay(void);
	int getYear(void);
	int getMonth(void);
	int getDay(void);
private: 
	int y, m, d;
};