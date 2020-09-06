
#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<Windows.h>
#include<time.h>
#include <math.h>
#include <iomanip>
using namespace std;
void main()
{
	setlocale(0,"");
	ofstream potik;
	const int n=10;
	int a=2, l=3;
    float x[n], r[n];
	int count=0;
	srand(time(0));
	for(int i=0; i<n; i++)
	{
		r[i]=rand()%(100)*0.01;
		x[i]=1-exp(-(pow(r[i]/l,a)));
		cout<<x[i]<<"\t";
	}
	cout<<endl;
	float tmp;
	for(int j=1; j<n; j++)
	{
		for(int i=0; i<n-j; i++)
		{
			if(x[i]>x[i+1])
			{
			tmp=x[i];
			x[i]=x[i+1];
			x[i+1]=tmp;
			}
		}
	}
	cout<<endl;
	potik.open("lab2.txt");
	for(int i=0; i<n; i++)
	{
		potik<<x[i]<<endl;
		cout<<x[i]<<"\t";
	}
	cout<<endl;
	potik.close();


	system("pause");

}
