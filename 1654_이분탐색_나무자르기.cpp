#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 10000

long long haveN, needN;
long long myLan[MAX];

bool canuse(long long m) {
	long long sum = 0;
	for (long long i = 0; i < haveN; i++) {
		sum += myLan[i] / m;
	}
	if (sum >= needN) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> haveN >> needN;
	long long high = 0;
	for (long long i = 0; i < haveN; i++) {
		cin >> myLan[i];
		high = max(high, myLan[i]);
	}
	long long left, right, mid, res = 0;
	left = 1;
	right = high;
	while (!(left > right)) {
		mid = (left + right) / 2;
		if (canuse(mid)) {
			res = max(mid, res);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res << "\n";
	return 0;
}