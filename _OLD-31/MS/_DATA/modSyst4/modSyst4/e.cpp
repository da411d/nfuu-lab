#include<iostream>
#include "stdafx.h"
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#include <math.h>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(0,"");
	int z1=1, z2=2, z3=3, n=15;
	int z;
	float r;
	srand(time(0));
	cout<<"Початковий стан "<<z<<endl;
	for(int i=0; i<n; i++)
	{
		r=((float)rand()/(RAND_MAX));
		if(r==1)
		{
			if(r<0.6)
			{
				cout<<z1<<endl;
				z=1;
			}
			else 
			{
				cout<<z1<<endl;
				z=2;
			}
		}
		//?
		else if(z==2)
		{
			if(r<0.2)
			{
				cout<<z1<<endl;
				z=1;
			}
			else if(r>2 && r<0.3)
			{
				cout<<z2<<endl;
				r=2;
			}
			else
			{
				cout<<z3<<endl;
				z=3;
			}
		}
		//
		else if(r<0.3)
		{
			cout<<z2<<endl;
			z=2;
		}
		else
		{
			cout<<z3<<endl;
			z=3;
		}
	}
	//
	
	system("pause");

}