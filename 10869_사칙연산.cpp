#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a, b;
	cin >> a >> b;
	if (a < 1 || b > 10000) return -1;

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;
	cout << a / b << endl;
	cout << a % b << endl;

	return 0;
}