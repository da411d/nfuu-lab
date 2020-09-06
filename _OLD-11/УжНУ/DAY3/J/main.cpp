#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
int min(int a,int b){return a<b?a:b;}
int main(){
    ifstream _fin; _fin.open("shift.in");
    ofstream _fout; _fout.open("shift.out");
    setlocale(LC_ALL, "Ukrainian");
    int n;
    char s1[1000000], s2[1000000];
    _fin >> n;
    _fin >> s1 >> s2;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(s1[j] == s2[(j+i)%n]){
                count++;
            }else{
                break;
            }
        }
        if(count == n){
            _fout << min(i, n-i);
            _fout.close();
            return 0;
        }
    }
    _fout << -1;
    _fout.close();
    return 0;
}
