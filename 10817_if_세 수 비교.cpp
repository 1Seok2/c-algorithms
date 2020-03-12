#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a,b,c;
	cin >> a>>b>>c;
	if (a < 1 || b < 1 || c < 1 ||
		a>100 || b>100 || c>100) return -1;
	int temp;
	if (a >= b) {
		if (b >= c) temp = b;
		else if (c >= b) {
			if (a >= c) temp = c;
			else if (a <= c) temp = a;
		}
	}
	else if (b >= a) {
		if (c >= b) temp = b;
		else if (b >= c) {
			if (a >= c) temp = a;
			else if (a <= c) temp = c;
		}
	}
	cout << temp << endl;
	return 0;
}