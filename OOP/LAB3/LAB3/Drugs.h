#pragma once
#include "Drug.h"
#include <iostream>
using namespace std;
class Drugs
{
public:
	Drugs(void);
	~Drugs(void);
	int getSum(void);
	void addItem(char*);
	void addItem(char*, int);
	//void getItem(int, Drug &);
	void print(void);

private:
	int current;
	Drug* list[1024];
};