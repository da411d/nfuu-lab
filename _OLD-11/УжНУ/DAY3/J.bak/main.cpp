#define echo cout <<
#define var int
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    setlocale(LC_ALL, "Ukrainian");
    int n;
    char s1[1000000], s2[1000000];
    cin >> n;
    cin >> s1 >> s2;
    for(int i=0; i<n; i++){
            int yeah = 0;
        for(int j=0; j<n; j++){
            if(s1[j] == s2[(j+i)%n]){
                //echo "Опа(" <<s1[j] << ")"<< endl;
                yeah++;
            }else{
                //echo "Блять(" <<s1[j] << "_"<<s2[i+j] << ")" << endl;
                break;
            }
        }
        if(yeah == n){
            //echo "Заїбісь! " <<endl;
            echo n-i;
            return 0;
        }else{
            //echo "Сука! "<< yeah <<endl;
        }
    }
    cout << -1;
    return 0;
}
