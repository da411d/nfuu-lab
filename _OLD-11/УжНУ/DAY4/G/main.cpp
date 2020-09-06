#include <iostream>

using namespace std;

int main()
{
    double a, p;
    cin>>a;
    a = 1 - a/100;
    p = a;
    int i;
    for(i=0; p>0.5; i++)
    {
        p *= a;
    }
    cout << i;
    return 0;
}
