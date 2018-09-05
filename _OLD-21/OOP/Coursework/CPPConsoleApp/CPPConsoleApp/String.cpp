#include "stdafx.h"
#include "String.h"

String::String() : String("")// : p(NULL)
{
	//capacity = 1024;
	//p = new char[capacity];
}

String::String(int cap)
{
	capacity = cap;
	p = new char[capacity];
}

String::String(char *str)
{
	capacity = strlen(str) + 1;
	p = new char[capacity];
	strcpy(p, str);
}

String::String(string str)
{
	/*capacity = str.length() + 1;
	p = new char[capacity];
	strcpy(p, str.c_str());*/
	//std::string s
	capacity = str.size() + 1;
	p = new char[str.size() + 1];
    p[str.size()] = '\0';
	memcpy(p, str.c_str(), str.size());
}

String::String(String& source)
{
	capacity = strlen(source.p) + 1;
	p = new char[capacity];
	strcpy(p, source.p);
}

String::~String(void)
{
	if (p != NULL) delete[] p;
}

String& String::operator+(String &source)
{
	long cap = strlen(source.getString()) + strlen(p) + 1;
	char *dest = new char[cap];
	strcpy(dest, p);
	strcat(dest, source.getString());
	delete[] p;
	p = dest;
	/*String temp(dest);
	*this = temp;
	delete[] dest;*/
	return *this; //temp;
}

String String::operator-(String &source)
{	
	char *pch, *substr = source.getString();
	char *dest = new char[strlen(p)+1];
	strcpy(dest, p);

	while ((pch = strstr(dest, substr)) != NULL)
	  strcpy(pch, pch + strlen(substr));
	
	String temp(dest);
	delete[] dest;
	return temp;
}

bool String::operator*(String &source)
{
	char *pch = strstr(p, source.getString());
	if (pch != NULL)
		return true;
	else 
		return false;
}

String& String::operator=(const String &Source)
{
	// êîï³þâàííÿ
	if (&Source != this)
	{
		if (p != NULL) delete[] p;
		p = new char[strlen(Source.p) + 1];
		strcpy(p, Source.p);
	}
	return *this;
}

/* Set methods */
void String::setString(char *_str)
{
	if (p != NULL) delete[] p;
	p = new char[strlen(_str) + 1];
	strcpy(p, _str);
}

/* Get methods */
char* String::getString()
{
	return p;
}

void String::print(ostream& os)
{
	SetConsoleOutputCP(1251);
	os << endl << "Ðÿäîê ñèìâîë³â:" << endl;
	os << getString() << endl;
}


ostream &operator<<(ostream &output, String& s)
{
	/*SetConsoleOutputCP(1251);
	output << endl << "ÐßÄÎÊ ÑÈÌÂÎË²Â" << endl;
	output << s.getString() << endl;*/
	s.print(output);
	return output;
}

istream &operator >> (istream &input, String& s)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl;
	/*cout << "Please, enter String" << endl;
	input >> s.p;
	*/
	cout << "Áóäü-ëàñêà, ââåä³òü ÐßÄÎÊ ÑÈÌÂÎË²Â" << endl;
	char buffer[size1];
	try
	{
		input.getline(buffer, size1, '\n');
		s.setString(buffer);
		input.clear();
	}
	catch (Error ex)
	{
		cout << ex.what() << endl;
	}
	return input;
}