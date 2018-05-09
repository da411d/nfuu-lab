#pragma once
#include <string>
#include <string.h>
using namespace std;

class charArray{
protected:
	char* value;
	int size = 1024;


public:
	//Constructors / Destructors
	charArray(void) {
		this->value = new char[size];
	};
	charArray(const char* input, int s) {
		this->value = new char[s+1];
		strcpy_s(this->value, s, input);
	};
	~charArray(void) {
		delete value;
	};

	//Getters / Setters
	int getSize() {
		return size;
	};
	int setSize(int n) {
		size = n;
		return size; //Дада, так задумано. Хз нашо, але так задумано
	};

	//Operators
	charArray operator+(char* val) {
		strcat_s(value, this->size, val);
		return *this;
	};
	charArray operator-(char* val) {
		while (value = strstr(value, val))
			memmove(value, value + strlen(val), 1 + strlen(value + strlen(val)));
		return *this;
	};
	int operator*(char* val) {
		return value - strstr(value, val);
	};
	void operator=(char* val) {
		strcpy_s(value, this->size, val);
	};
	friend ostream& operator<<(ostream &io, charArray val) {
		io << val;
		return io;
	};
	friend ostream& operator>>(ostream &io, charArray val) {
		io >> val;
		return io;
	};
};