#include <iostream>

using namespace std;

int main()
{
    bool t = 0;
    cin>>n;
    char str[n];
    cin>> str;
    for (int i=1; i<n; i++)
    {
        if(str[i-1] == str[i])
        {
             t = 1;
        }
        else
        {
            t = 0;
            break;
        }
    }
    if (t == 1)
        for(i =1; i<n; i++)
            cout<<i<<" "<<i<<endl;


    return 0;
}
