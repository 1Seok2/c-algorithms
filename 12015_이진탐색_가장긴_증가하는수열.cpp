#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable : 4996)
#define MAX 1000000
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, a;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (v.empty() || v.back() < a) {
			v.push_back(a);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a);
			*it = a;
		}
	}
	cout << v.size() << "\n";
	return 0;
}
