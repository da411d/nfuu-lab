#pragma once
#include <string>
#include "charArray.h"
using namespace std;

class bigInt : public charArray
{
private:
public:
	//Operators
	bigInt operator+(bigInt val){
		return *this;
	};
	bigInt operator-(bigInt val){
		return *this;
	};
	bigInt operator*(bigInt val){
		return *this;
	};
	bigInt operator/(bigInt val){
		return *this;
	};


	bool operator<(bigInt right){
		if(strlen(this->value) < strlen(right.value)){
			return true;
		}
		else if(strlen(this->value) > strlen(right.value)){
			return false;
		}
		else{ //If same length
			for(int i = 0; this->value[i]; i++){
				if(this->value[i] < right.value[i]){
					return true;
				}
				else if(this->value[i] > right.value[i]){
					return false;
				}
			}
			return false;
		}
	};
	bool operator==(bigInt right){
		if(strlen(this->value) != strlen(right.value))return false;
		for(int i = 0; this->value[i]; i++){
			if(this->value[i] != right.value[i]){
				return false;
			}
		}
		return true;
	};
	bool operator>(bigInt right){
		return !(*this < right || *this == right);
	};

	void operator=(char* val){
		strcpy(value, val);
	};
	friend ostream& operator<<(ostream &io, bigInt val){
		io << val;
		return io;
	};
	friend ostream& operator>>(ostream &io, bigInt val){
		io >> val;
		return io;
	};
};