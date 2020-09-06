#include<iostream>
//#include "stdafx.h"
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#include <math.h>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(0,"");
	const int n=15;
	//int z1=1, z2=2, z3=3;
	int z=1;
	//float r;
	float r[n];
	srand(time(0));

	cout<<"Початковий стан "<<"z1"<<endl;
	for(int i=0; i<n; i++)
	{
		r[i]=((float)rand()/(RAND_MAX));
		cout<<r[i]<<"\t";
		if(z==1)
		{
			if(r[i]<0.6)
			{
				z=1;
				cout<<"z1"<<endl;
				
			}
			else 
			{
				z=2;
				cout<<"z2"<<endl;
				
			}
		}
		
		else if(z==2)
		{
			if(r[i]<0.2)
			{
				z=1;
				cout<<"z1"<<endl;
				
			}
			
			else if(r[i]>0.2 && r[i]<0.3)
				
			{

				z=3;
				cout<<"z3"<<endl;
				
			}
			
			else
			{
				z=2;
				cout<<"z2"<<endl;
				
			}
		}
		
		else
		{
			 if(r[i]<0.3)
			{
				z=2;
				cout<<"z2"<<endl;
			
			}
			else
			{
				z=3;
				cout<<"z3"<<endl;
			
			}
		}
	}
	
	
	//cout<<"Початковий стан "<<z1<<endl;
	////вивести матрицю станів

	////r=((float)rand()/(RAND_MAX));
	////cout<<"r= "<<r<<endl;
	//for(int i=0; i<n; i++)
	//{
	//	r[i]=((float)rand()/(RAND_MAX));
	//	cout<<r[i]<<"\t";
	//	if(z==1)
	//	{
	//		if(r[i]<0.6)
	//		{
	//			z=1;
	//			cout<<"z1"<<endl;
	//			
	//		}
	//		else 
	//		{
	//			z=2;
	//			cout<<z1<<endl;
	//			
	//		}
	//	}
	//	//?
	//	else if(z==2)
	//	{
	//		if(r[i]<0.2)
	//		{
	//			z=1;
	//			cout<<z1<<endl;
	//			
	//		}
	//		else if(r[i]>2 && r[i]<0.3)
	//		{

	//			z=2;
	//			cout<<z2<<endl;
	//			
	//		}
	//		else
	//		{
	//			z=3;
	//			cout<<z3<<endl;
	//			
	//		}
	//	}
	//	//
	//	else if(r[i]<0.3)
	//	{
	//		z=2;
	//		cout<<z2<<endl;
	//		
	//	}
	//	else
	//	{
	//		z=3;
	//		cout<<z3<<endl;
	//		
	//	}
	//}
	//
	
	system("pause");

}