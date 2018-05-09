#include <iostream>
#include "charArray.h"
using namespace std;

void main(){
	charArray* a = new charArray("Hello World", 10);

	cout << a;
}