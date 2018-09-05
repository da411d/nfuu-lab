#pragma once

#include <iostream>
#include <windows.h>
#include "Function.h"
#include "Error.h"

#define size1 255

using namespace std;

class String
{
	protected:
		char *p; // �������� �� ������� �����
		int capacity;  // ����� �����
	public:
		String();
		String(int);
		String(char*);
		String(string);
		String(String&);
		virtual ~String();

		void setString(char *);
		char *getString();

		virtual String &operator+ (String&); // ���������� �������� ������������ �����
		String operator- (String&);
		bool operator* (String&);
		virtual String& operator= (const String&);
		virtual void print(ostream &os);

		friend ostream& operator<< (ostream &output, String&);
		friend istream& operator >> (istream &input, String&);
};

