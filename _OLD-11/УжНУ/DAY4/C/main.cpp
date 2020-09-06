#include <iostream>
using namespace std;
double fakt(int n){
    double s = 1;
    for(int i=1; i<=n; i++){
        s *= i;
    }
    return s;
 }
int main()
{
    int t;

    cin >> t;

    for(int i = 0; i<t; i++){
        double n, m, k, l, q, L;
        double p;
        cin >> n >> m >> k;
        l = n-m;
        q = m-k;

            p = fakt(m)/(fakt(k)*fakt(m-k)) * fakt(l)/(fakt(q)*fakt(l-q)) * (fakt(m)*fakt(n-m))/fakt(n);
            cout << p;

    }
    return 0;
}
