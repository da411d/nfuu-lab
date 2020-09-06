#include <iostream>
using namespace std;

bool check(long a, int lim) {
	while (a > 0 && lim > 0){
		if (a % 4 == 0) {
			return true;
		}
		a -= 7;
		lim--;
	}
	return a == 0;
}
int main() {
	long a, b, k, c;
	cin >> a >> b >> k;
	for (long i = a; i < b; i++) {
		c += check(i, k);
	}
	cout << c;
	return 0;
}