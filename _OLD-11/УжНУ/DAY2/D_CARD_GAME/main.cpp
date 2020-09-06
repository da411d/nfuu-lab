#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin>> n >> m;
    int mas[m];
    for(int i=0; i<m; i++)
    {
        cin>>mas[i];
    }

    if (n==1)
    {
        cout<<"YES";
        return 0;
    }

    if(n == m)
    {
        cout<<"YES";
        return 0;
    }

    int a[m], b[m], c[m], d[m], e[m];
    int j = 0, k = 0, l= 0, h=0, el = 0;

    for(int i=0; i<m; i++)
    {
        if(mas[i] == 1)
        {
            j++;
            a[j] = mas[i];
        }
        if(mas[i]== 2)
        {
            k++;
            b[k] = mas[i];
        }
        if(mas[i] == 3)
        {
            l++;
            c[l] = mas[i];
        }
        if(mas[i] == 4)
        {
            h++;
            d[h] = mas[i];
        }
        if(mas[i] == 5)
        {
            el++;
            e[el] = mas[i];
        }
    }

    if(j==m || h == m||l==m || k==m || el==m )
        {
            cout<< "NO";
            return 0;
        }

    int ce;
    int masm[5] = {j, h, l, k, el};
    int max =0;
    for(int i = 1; i<5; i++)
    {
        if(masm[i-1] > masm[i])
        {
            ce = masm[i-1];
            masm[i-1] = masm[i];
            masm[i] = ce;
            max = masm[i];
        }
    }
    int rez;
    if(masm[0]>0)
    {
        rez = max *5;
        if(rez > n)
            cout<<"NO";
        else
            cout<<"YES";
    }
    else if (masm[0] == 0)
    {
        rez = max *5;
        if(rez > n)
        {
            rez = max *4;
            if(rez > n && masm[1]==0)
                {
                    rez = max *3;
                    if(rez > n && masm[2]==0)
                    {
                        rez = max *2;
                        if(rez > n)
                            cout<<"NO";
                        else
                            cout<< "YES";
                    }


                }
            else
                cout<<"YES";
        }
        else
            cout<<"YES";

    }

    return 0;
}

