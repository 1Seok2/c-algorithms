#include <iostream>
#include <string>
using namespace std;


int main() {
	int n, m;
	int count = 0;
	cin >> n >> m;
	while (!(n == 0 && m == 0)) {
		if (count > 0) {
			cin >> n >> m;
			if (n == 0 && m == 0) break;
		}
		if (m%n == 0) {
			cout << "factor\n";
		}
		else if (n%m == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
		count++;
	}
	
	return 0;
}