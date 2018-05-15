#ifndef CPERSON_H
#define CPERSON_H

#include <iostream>
#include <windows.h>
#include "Function.h"
#include "Error.h"

#define size1 255

using namespace std;

/* клас ј¬“ќћќЅ≤Ћ№ */
class CCar {
  protected:	 
	 char *m_pszBrand; /* марка автомоб≥л€ */
	 char *m_pszColor; /* кол≥р */
	 float m_EngineVolume; /* об'Їм двигуна */
	 unsigned int m_EnginePower; /* потужн≥сть */
  public:
	 CCar();
	 CCar(char*, char*, float, unsigned int);
	 CCar(CCar&); 
	 virtual ~CCar();

	 void setBrand(char*);
	 void setColor(char*);
	 void setEngineVolume(float);
	 void setEnginePower(unsigned int);

	 char* getBrand();
	 char* getColor();
	 float getEngineVolume();
	 unsigned int getEnginePower();
	
	 virtual void Read();
	 virtual void Output();
	 
	 friend ostream& operator<< (ostream &output, CCar&);
     friend istream& operator>> (istream &input, CCar&);

 	 CCar& operator*(const char*);
	 friend CCar& operator+=(CCar&, const unsigned int&);
	 CCar& operator=(CCar&);
};

#endif