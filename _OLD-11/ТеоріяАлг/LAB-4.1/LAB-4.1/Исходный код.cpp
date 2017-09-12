#include<iostream>
#include<time.h>
#include<string.h>

using namespace std;
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int progress_1(int a, int k, int n){
	if(n<=0)return a;
	return progress_1(a, k, n-1)+k;
}

int progress_2(int a, int k, int n){
	if(n<=0)return a;
	return progress_2(a+k, k, n-1);
}

void main() {
	setlocale(LC_ALL, "Ukrainian");
	int k = 0, n = 1;
	int arr[1000];
	cout << "Кiлькiсть членiв> ";cin >> n;
	cout << "Перший член> ";cin >> arr[0];
	cout << "Різниця> ";cin >> k;
	
	for(int i=1; i<n; i++){
		arr[i] = progress_2(arr[0], k, i);
	}

	mergeSort(arr, 0, n - 1);
	cout << "Посортований масив: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Сума прогресiї: " << (arr[0] + arr[n-1])*n/2;
	system("pause>>NUL");
}





void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = new int[n1];
	int *R = new int[n2];

	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r) {
	if(l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}