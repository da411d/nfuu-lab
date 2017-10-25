#pragma once
class Storage
{
protected: 
	int memorySize;
public:
	Storage(void){}
	int getMemorySize(){return memorySize;}
	void setMemorySize(int n){memorySize = n;}
};

