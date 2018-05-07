#pragma once
#include <string>
using namespace std;

class charArray{
private:
	char* value;
	int maxLength;


public:
	//Constructors / Destructors
	charArray(void) {
		this->value = new char[maxLength];
	};
	charArray(char* input) {
		this->value = new char[maxLength];
		strcpy(this->value, input);
	};
	~charArray(void) {
		delete value;
	};

	//Getters / Setters
	int getMaxLength() {
		return maxLength;
	};
	int setMaxLength(int n) {
		maxLength = n;
		return maxLength; //Дада, так задумано. Хз нашо, але так задумано
	};

	//Operators
	charArray operator+(char* val) {
		strcat(value, val);
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
		strcpy(value, val);
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