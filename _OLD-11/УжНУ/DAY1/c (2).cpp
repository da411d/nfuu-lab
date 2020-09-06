#include <iostream>
using namespace std;
int main()
{
	int h, p,r,s, hp = 0, hr = 0, hs = 0, pr = 0, ps = 0, rs = 0;
	cin>>h>>p>>r>>s;

	while ((h>0)&& (p>0))
	{
		hp++;
		h--;
		p--;
	}
	while(h>0 && r>0)
	{
		hr++;
		h--;
		r--;
	}
	while(h>0 && s>0)
	{
		hs++;
		h--;
		s--;
	}
	while(s>0 && r>0)
	{
		rs++;
		r--;
		s--;
	}
	while(p>0 && s>0)
	{
		ps++;
		p--;
		s--;
	}
	while(p>0 && r>0)
	{
		pr++;
		p--;
		r--;
	}




	cout<<hp<< " "<<hs<<" "<<hr<<" "<<pr<<" "<<ps<< " "<<rs;
	return 0;
}
