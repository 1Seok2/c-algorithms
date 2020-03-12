#include <iostream>
using namespace std;

int main() {
	bool num[1000001];

	int m, n;
	int i, j;

	cin >> m >> n;

	for (i = 2; i <= 1000000; i++) {
		num[i] = true;
	}
	num[1] = false;

	for (i = 2; (i*i) <= 1000000; i++) {
		if (num[i] == true) {
			for (j = i + i; j <= 1000000; j += i) {
				num[j] = false;
			}
		}
	}
	for (i = m; i <= n; i++) {
		if (num[i]) cout << i << endl;
	}
	return 0;
}