#ifndef CPERSON_H
#define CPERSON_H

#include <iostream>
#include <windows.h>
#include "Function.h"
#include "Error.h"

#define size1 255

using namespace std;

/* ���� ���������� */
class CCar {
  protected:	 
	 char *m_pszBrand; /* ����� ��������� */
	 char *m_pszColor; /* ���� */
	 float m_EngineVolume; /* ��'�� ������� */
	 unsigned int m_EnginePower; /* ��������� */
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