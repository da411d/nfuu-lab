#include "StdAfx.h"
#include "Error.h"

Error::Error(void)
{
	*strMas = 0;
}

Error::Error(char *s) 
{
	strcpy(strMas, s);
}

Error::~Error(void)
{
}

char* Error::what()
{
	return strMas;
}

