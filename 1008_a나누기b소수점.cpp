#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	long double a, b;
	cin >> a >> b;
	if (a <= 0 || b >= 10) return -1;

	cout << setprecision(13) << a / b << endl;

	return 0;
}