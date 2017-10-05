#pragma once
#include "Drug.h"
#include <iostream>
using namespace std;
class DrugStore{
public:
	DrugStore(void);
	~DrugStore(void);
	int getSum(void);
	void addItem(char*);
	void addItem(char*, int);
	void addItem(char*, int, int);
	void print(void);

	int current;
	Drug list[1024];
};