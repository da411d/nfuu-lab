#include "stdafx.h"
#include "Function.h"


int GetInt(istream& is) {
	int value;
	while(true)
	{
		is >> value; 				
		if(is.peek() == '\n')
		{ 		
			is.get();				
			break;
		}
		else 
		{
			cout << "������i�� �������� (��i������ �i�� �����):"
				<< endl; 
			is.clear();				
			while(is.get() != '\n') {};	
		}
	}
	return value;
}

float GetFloat(istream& is)
{
	float value;
	while (true)
	{
		is >> value;
		if (is.peek() == '\n')
		{
			is.get();
			break;
		}
		else
		{
			cout << "������i�� �������� (��i������ ����� �����):"
				<< endl;
			is.clear();
			while (is.get() != '\n') {};
		}
	}
	return value;
}