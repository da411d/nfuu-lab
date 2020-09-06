#include <iostream>
using namespace std;


int abs(int n){return n*(n>0?1:-1);}
bool arr_contains(int* arr, int n, int v){
    for(int i=0; i<n*2; i++){
        //cout << "> " << "check " << arr[i] << " and " << v << endl;
        if(arr[i] == v){
            //cout << "> " << "RETURN TRUE" << endl << endl;
            return 1;
        }
    }
   // cout << "> " << "RETURN FALSE" << endl << endl;
    return 0;
}

int n, A[200000];
int main(){
    cin >> n;
    for(int i=0; i<2*n; i++){
        cin >> A[i];
    }
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n - 1; j++){
            if(abs(A[j]) > abs(A[j+1])){
                swap(A[j], A[j+1]);
            }
        }
    }
    for(int i=0; i<2*n; i++){
        cout << A[i] << " ";
    }
cout << endl;
    int d = A[1] - A[0];
    for(int i=0; i<2*n; i++){  //offset
        for(int j=1; j<2*n - 1; j++){ //len
            bool shit = 0;
            d = A[i+j] - A[i];
            int next = A[i+j];
            for(int k=0; k<n-j+1; k++){
                next += d;
                //cout << "SEARCH " << next << " in " <<(arr_contains(A, n, next) ? "true" : "false") << endl;;
                if(!arr_contains(A, n, next) || (k==n-j && arr_contains(A, n, next))){
                    shit = true;
                    break;
                }
            }
            cout << "X3 " << i << " " << j << " " << endl;
            if(shit){
                break;
            }
        }
    }
    return 0;
}
