#include <iostream>
#include <time.h>
using namespace std;

int bsearch(int*a, int start, int end, int search){
	int middle = (start+end)/2;
	if(end < start)return -1;
	if(search == a[middle]) return middle;

	if(search < a[middle])return bsearch(a, start, middle-1, search);
	else if(search > a[middle])return bsearch(a, middle+1, end, search);
	else return start;
}

void main(){
	setlocale(LC_ALL, "Ukrainian");
	srand(time(0));
	const int n = 100;
	int arr[n];
	for(int i=0; i<n; i++){
		arr[i] = i*20 + rand()%20;
		cout << arr[i] << " ";
	}
	int search = arr[rand()%n];
	cout << "\r\nЯ шукаю число " << search << endl;
	cout << bsearch(arr, 0, n, search);
	system("pause>>NUL");
}