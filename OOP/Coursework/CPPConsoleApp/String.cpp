#include "stdafx.h"
#include "Car.h"

CCar::CCar() : m_pszBrand(NULL), m_pszColor(NULL), 
		m_EngineVolume(0.0f), m_EnginePower(0)
{

}

CCar::CCar(char *_car_brand, char *_color, 
				 float _engine_volume, unsigned int _engine_power)
{
	m_pszBrand = new char[strlen(_car_brand) + 1];
	strcpy(m_pszBrand, _car_brand);
	m_pszColor = new char[strlen(_color) + 1];
	strcpy(m_pszColor, _color);
	m_EngineVolume = _engine_volume;
	m_EnginePower = _engine_power;
}

CCar::CCar(CCar& cSource)
{
	m_pszBrand = new char[strlen(cSource.m_pszBrand) + 1];
	strcpy(m_pszBrand, cSource.m_pszBrand);
	m_pszColor = new char[strlen(cSource.m_pszColor) + 1];
	strcpy(m_pszColor, cSource.m_pszColor);
	m_EngineVolume = cSource.m_EngineVolume;
	m_EnginePower = cSource.m_EnginePower;
}

CCar::~CCar(void)
{
	if (m_pszBrand != NULL) delete[] m_pszBrand;
	if (m_pszColor != NULL) delete[] m_pszColor;
}

CCar& operator+=(CCar &left, const unsigned int &_power)
{
	left.m_EnginePower += _power;
	return left;
}

CCar& CCar::operator*(const char *_color)
{
	if (m_pszColor != NULL) delete[] m_pszColor;
	m_pszColor = new char[strlen(_color) + 1];
	strcpy(m_pszColor, _color);
	return *this;
}

CCar& CCar::operator=(CCar &cSource)
{
    // копіювання
	m_pszBrand = new char[strlen(cSource.m_pszBrand) + 1];
	strcpy(m_pszBrand, cSource.m_pszBrand);
	m_pszColor = new char[strlen(cSource.m_pszColor) + 1];
	strcpy(m_pszColor, cSource.m_pszColor);
	m_EngineVolume = cSource.m_EngineVolume;
	m_EnginePower = cSource.m_EnginePower;
    // повернути існуючий об'єкт
    return *this;
}

/* Set methods */
void CCar::setBrand(char *_car_brand)
{
	m_pszBrand = new char[strlen(_car_brand) + 1];
	strcpy(m_pszBrand, _car_brand);
}

void CCar::setColor(char *_color)
{
	m_pszColor = new char[strlen(_color) + 1];
	strcpy(m_pszColor, _color);
}

void CCar::setEngineVolume(float _engine_volume)
{
	m_EngineVolume = _engine_volume;
}

void CCar::setEnginePower(unsigned int _engine_power)
{
	m_EnginePower = _engine_power;
}

/* Get methods */
char* CCar::getBrand()
{
	return m_pszBrand;
}

char* CCar::getColor()
{
	return m_pszColor;
}

float CCar::getEngineVolume()
{
  return m_EngineVolume;
}

unsigned int CCar::getEnginePower()
{
  return m_EnginePower;
}

void CCar::Read()
{
	cout << "Введіть потужність автомобіля: ";
	setEnginePower(GetInt(cin));
}

void CCar::Output()
{
	cout << "Потужність автомобіля: " << m_EnginePower << endl;
}

ostream &operator<<(ostream &output, CCar& c)
{
   SetConsoleOutputCP(1251);
   /*output << " CAR information" << endl;
   output << "Brand: " << c.m_pszBrand << endl;
   output << "Color: " << c.m_pszColor << endl;
   output << "Engine volume: " << c.m_EngineVolume << endl;
   output << "Engine power: " << c.m_EnginePower << endl;
	*/   
   output << endl << "Інформацiя про АВТОМОБІЛЬ" << endl; 
   output << "Марка: " << c.getBrand() << endl;
   output << "Колір: " << c.getColor() << endl;
   output << "Об'єм двигуна: " << c.getEngineVolume() << endl;
   output << "Потужність: " << c.getEnginePower() << endl;

   return output;
}

istream &operator>>(istream &input, CCar& c)
{
  
  SetConsoleCP(1251);// встановлення кодової сторінки win-cp 1251 в потік введення
  SetConsoleOutputCP(1251);
  cout << endl;
  /*cout << "Please, enter information about CAR " << endl;
  cout << "Brand: ";
  input >> c.m_pszBrand;
  cout << "Color: ";
  input >> c.m_pszColor;
  cout << "Engine volume: ";
  input >> c.m_EngineVolume;
  cout << "Engine power: ";
  input >> p.m_EnginePower;
  */
  cout << "Будь-ласка, введіть інформацію про АВТОМОБІЛЬ" << endl;  
  char buffer[size1];
  try
	{
		cout << "Марка: ";
		input.getline(buffer,size1,'\n');
		c.setBrand(buffer);
		cout << "Колір: ";
		input.getline(buffer,size1,'\n');
		c.setColor(buffer);
		cout << "Об'єм двигуна: ";
		c.setEngineVolume(GetFloat(input));
		cout << "Потужність: ";
		c.setEnginePower(GetInt(input));
		input.clear();
	}
	catch(Error ex)
	{
		cout << ex.what()<<endl;
	}

  return input;
}
