#pragma once
#include <iostream>
#include "Storage.h"
class HDD: public Storage
{
protected: 
	char* name;
	int cylinders, rows, sectors;
public:
	HDD(void){
		
	}
	char* getName(){return name;}
	int getCylinders(){return cylinder;}
	int getRows(){return rows;}
	int getSectors(){return sectors;}
	void setName(char* n){name=n;}
	void setCylinders(int n){cylinders=n;}
	void setRows(int n){rows=n;}
	void setSectors(int n){sectors=n;}
};

