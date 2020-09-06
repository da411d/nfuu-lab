#include <iostream>
using namespace std;

int main() {
	int N, min, max, mean;
	cin >> N >> min >> max >> mean;
	if(mean != ((max + min)/N))
		cout << "Impossibe";
	else
	{
		int a = (N * mean - max - min)/(N - 2);
		int b = N * mean - max - min - a;
		cout << a << " "<< b <<" "<< max << " " << min;
	}
	return 0;
}
