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
			cout << "Повторiть введення (очiкується цiле число):"
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
			cout << "Повторiть введення (очiкується дійсне число):"
				<< endl;
			is.clear();
			while (is.get() != '\n') {};
		}
	}
	return value;
}