#include <iostream>
#include "DigitalClock.h"
using namespace std;

void main(){
	setlocale(LC_ALL, "Ukrainian");
	DigitalClock clock;
	int y, m, d, hh, mm, ah, am;
	cout << "¬веди дату: d m yyyy\b\b\b\b\b\b\b\b";
	cin >> d >> m >> y;
	cout << "¬веди час: hh mm\b\b\b\b\b";
	cin >> hh >> mm;
	
	cout << "¬веди час будильника: hh mm\b\b\b\b\b";
	cin >> ah >> am;
	system("cls");
	clock.setDate(y, m, d);
	clock.setTime(hh, mm);
	clock.setAlarm(ah, am);
	clock.start();
}