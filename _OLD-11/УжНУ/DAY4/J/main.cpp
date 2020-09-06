#include <iostream>
using namespace std;
int main()
{
    float a, b, c, d;
    float ab, cd, p;
    cin>> a>> b >> c >> d;
    ab = a/b;
    cd = c/d;
    p = ab +1/(a+b+c+d);
    cout<<p;
    return 0;
}
