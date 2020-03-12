#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a < 2 || b < 2 || c < 2 ||
		a > 10000 || b > 10000 || c > 10000) return -1;

	cout << (a + b) % c << endl;
	cout << (a%c + b%c) % c << endl;
	cout << (a * b) % c << endl;
	cout << (a%c*b%c) % c << endl;

	return 0;
}