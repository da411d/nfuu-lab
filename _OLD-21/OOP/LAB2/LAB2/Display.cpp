#include "Display.h"
#include <iostream>
using namespace std;

Display::Display(void){}
Display::~Display(void){}

void Display::render(DateController date, TimeController time){
	int 
		y = date.getYear(),
		m = date.getMonth(),
		d = date.getDay(),
		hh = time.getHours(),
		mm = time.getMinutes(),
		ss = time.getSeconds();
	
	cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	if(d<10)cout<<"0";cout<<d;
	cout << ".";
	if(m<10)cout<<"0";cout<<m;
	cout << ".";
	cout<<y;
	cout << " ";
	if(hh<10)cout<<"0";cout<<hh;
	cout << ":";
	if(mm<10)cout<<"0";cout<<mm;
	cout << ":";
	if(ss<10)cout<<"0";cout<<ss;
}