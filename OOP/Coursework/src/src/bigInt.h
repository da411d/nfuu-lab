/*
#pragma once
#include <string>
#include "charArray.h"
using namespace std;

class bigInt : public charArray
{
protected:
	int* value;

public:
	bigInt(char* input){
		int* v = new int[strlen(input)];
		for(int i = 0; i < strlen(input); i++){
			v[i] = input[i] - 'a';
		}

		this->value = v;
		this->size = strlen(input);
	};
	bigInt(bigInt* input){
		int* v = new int[input->getSize()];
		for(int i = 0; i < input->getSize(); i++){
			v[i] = input->value[i];
		}

		this->value = v;
		this->size = input->getSize();
	};


	//Operators
	bigInt operator+(bigInt that){
		bigInt a = new bigInt(*this);
		bigInt b = new bigInt(that);
		int length;
		if(a.getSize() > b.getSize()){
			length = a.getSize() + 1;
		}
		else{
			length = b.getSize() + 1;
		}
		for(int i = 0; i < length; i++){
			b.value[i] += a.value[i];
			b.value[i + 1] += (b.value[i] / 10);
			b.value[i] %= 10;
		}

		if(b.value[length - 1] == 0)
			length--;

		return b;
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
		if(this->size < right.size){
			return true;
		}
		else if(this->size > right.size){
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
		if(this->size != right.size)return false;
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

	void operator=(char* input){
		int* v = new int[strlen(input)];
		for(int i = 0; i < strlen(input); i++){
			v[i] = input[i] - 'a';
		}

		this->value = v;
		this->size = strlen(input);
	};
	void operator=(bigInt* input){
		int* v = new int[input->getSize()];
		for(int i = 0; i < input->getSize(); i++){
			v[i] = input->value[i];
		}

		this->value = v;
		this->size = input->getSize();
	};

	friend ostream& operator<<(ostream &io, bigInt val){
		io << val;
		return io;
	};
	friend ostream& operator>>(ostream &io, bigInt val){
		io >> val;
		return io;
	};
};*/