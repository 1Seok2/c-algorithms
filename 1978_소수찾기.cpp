#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

bool sosu(int n) {
	if (n == 1) return false;
	for (int i = 2; i < n - 1; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,num;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (sosu(num)) {
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}