#pragma once

#include <iostream>
#include <cstring> 

using namespace std;

class Error
{ 
	char strMas[80];
public:
	Error();
	Error(char *s);
    ~Error(void);
	char* what();	
};

