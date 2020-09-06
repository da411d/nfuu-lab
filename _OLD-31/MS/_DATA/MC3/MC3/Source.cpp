#include<iostream>
#include<time.h>
using namespace std;

int main() 
{ 
	setlocale(LC_ALL,"Ukrainian");
	const int n=30;
	int min_x=0,max_x=3,min_y=0,max_y=3;
	double xi[n],yi[n];
	double r1, r2;

	int b1=1, b2=3, a1=3, a2=1;
	double x1[n],x2[n];
	srand(time(0));
	cout<<"  | X\tY\n";
	cout<<"  | -----\n";
	for (int i = 0; i < n; i++)
	{
		
		xi[i]= min_x + rand()%(max_x - min_x);
		yi[i]= min_y + rand()%(max_y - min_y);

		if(i<9){cout<<" ";}
		
		cout<<i+1<<"| "<<xi[i]<<"\t"<<yi[i]<<"\n";
	
	}

	cout<<"  | X1\tX2\n";
	cout<<"  | -----\n";
	for (int i = 0; i < n; i++)
	{
		r1=rand()%(100)*0.01;
		r2=rand()%(100)*0.01;
		//cout<<r1<<""<<r2<<endl;
		x1[i]= (b1-a1)*r1+a1;
		x2[i]= (b2-a2)*r2+a2;
			if(i<9){cout<<" ";}
		
		cout<<i+1<<"| "<<x1[i]<<"\t"<<x2[i]<<"\n";
	
	}
    system("pause"); 
    return 0; 
}