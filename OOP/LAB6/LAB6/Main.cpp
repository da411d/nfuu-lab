#include <iostream>
#include <time.h>
using namespace std;

/**
	Створити шаблонну функцію для знаходження 
	мінімального значення елементів масиву.
*/
template <typename _>
_ arr_max(_ *O, int l){
	_ o=O[0];
	for(l--;l-1;l--)o=o<O[l]?O[l]:o;
	return o;
}


void main(){
	setlocale(0, "");
	srand(time(0));
	
	cout << "/**" << endl;
	cout << "	Частина 1 - Пошук максимального числа" << endl;
	cout << "*/" << endl;
	const int _SIZE = 20;
	int arr[_SIZE];
	for(int i=0; i<_SIZE; i++){
		arr[i] = rand()%20;
		cout << arr[i] << " ";
	}
	cout << endl; 
	cout << "Max element: " << arr_max(arr, _SIZE) << endl;
	system("pause>NUL");
}