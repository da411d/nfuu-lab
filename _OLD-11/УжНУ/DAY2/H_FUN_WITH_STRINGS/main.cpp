#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int n, m;
int ARR[100000], ARR_LEN = 0;
void _i(string &s, int p, char c){
    if(p == 0){
        s = c+s;
    }else{
        char ss[] = {c};
        s.insert(p, ss);
    }
}
void _d(string &s, int p){
    s.erase(p-1, 1);
}
void _q(string s, int a, int b){
    s += "z";
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[a+i-1] == s[b+i-1]){
            cnt++;
        }else{
            break;
        }
    }
    ARR[ARR_LEN] = cnt;
    ARR_LEN++;
}
int main()
{
    int p, a, b;
    char c, cmd;


    cin >> n >> m;
    string s;
    getline(cin, s);
    for(int i=0; i<n;i++){
        cin >> cmd;
        s += cmd;
    }
    for(int i=0; i<m; i++){
        cin >> cmd;
        switch(cmd){
        case 'i':
            cin >> p >> c;
            _i(s, p, c);
            break;

        case 'd':
            cin >> p;
            _d(s, p);
            break;

        case 'q':
            cin >> a >> b;
            _q(s, a, b);
            break;
        }
    }
    for(int i=0; i<ARR_LEN; i++){
        cout << ARR[i];
    }
    return 0;
}
