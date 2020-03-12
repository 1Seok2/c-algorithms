#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//에라토스테네스의 체로 소수구하기

void getsosu(int n) {
	int *arr;
	arr = new int[n];

	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i*i <= n; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	getsosu(n);
	return 0;
}