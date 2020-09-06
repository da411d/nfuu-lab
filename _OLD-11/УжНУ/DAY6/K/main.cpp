#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int n, o;
   cin>>n;
   for(int i=0; i<n; i++)
   {
   o=n+(n-2*i)/(2)+pow(((n-2*i)/2),2);
   }
    cout<<o;
    return 0;
}
