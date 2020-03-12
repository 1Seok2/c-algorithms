#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)
#define MAX 1000000
using namespace std;

long long a[MAX];
long long n;

void bs(long long b) {
	long long left = 0, right = n - 1,mid;
	while (!(left > right)) {
		mid = (left + right) / 2;
		if (b > a[mid]) {
			left = mid + 1;
		}
		else if (b == a[mid]) {
			cout << 1 << "\n";
			return;
		}
		else {
			right = mid - 1;
		}
	}
	cout << 0 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long m, b, left = 0, right = n - 1, mid, res = 0;
	cin >> m;
	for (long long j = 0; j < m; j++) {
		cin >> b;
		bs(b);
	}
	return 0;
}
