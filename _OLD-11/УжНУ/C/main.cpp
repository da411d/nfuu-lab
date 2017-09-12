#include <iostream>

using namespace std;

double fakt(int n)
{
	double s = 1;
	for(int i = 1; i<=n; i++)
	{
		s *= i;
	}
	return s;
}

int main()
{
	double t, n, m, k;
	cin>>t;
	double p;

	for(int i=0; i<t; i++)
	{
		cin>>n>>m>>k;
		double l = n-m;
		double q = m-k;


		if(l<=k)
		{
			double value = 1;
			cout<<value;
		}
		else
		{
			p = fakt(m)/(fakt(k)*fakt(m-k)) *
				fakt(l)/(fakt(q)*fakt(l-q)) *
				(fakt(m)*fakt(n-m))/fakt(n);
			cout<<p<<endl;
		}
	}
    return 0;
}
