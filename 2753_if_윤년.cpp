#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a;
	cin >> a;
	if (1 > a || 4000 < a) return -1;

	if (a % 4 == 0) {
		if (a % 100 == 0) {
			if (a % 400 == 0) {
				cout << 1 << endl;
				return 0;
			}
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}