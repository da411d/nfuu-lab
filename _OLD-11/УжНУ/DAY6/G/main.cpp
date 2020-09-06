#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int array_count(int *arr, int n, int value){
	int s = 0;
	for(int i=0; i<n; i++)s += arr[i]==value;
	return s;
}

int main(){
	int n = 0;
	string str, tmp;
	int arr[1000];


    getline(cin, str);
    int offset = 0;
    str = " "+str;
    do{
        tmp = str.substr(offset, str.find(" ", offset+1));
        offset = str.find(" ", offset+1);

        int q = atoi(tmp.c_str());
		arr[n++] = q;
    }while(offset >= 0);

    for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(arr[j] > arr[j+1])swap(arr[j], arr[j+1]);
		}
    }
	int amount = 0, l;
	for(int i=0; i<n; i++){
	cout << arr[i] << ", ";
		l =  arr[i] + 1;
		amount +=l;
	}

	cout<<amount;
    return 0;
}
