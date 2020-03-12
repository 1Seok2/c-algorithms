#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include<algorithm>
#define MAX 1000000000
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = n; i != 0; i /= 10) {
		v.push_back(i % 10);
	}
	sort(v.begin(), v.end());
	for (int i = v.size()-1; i >=0; i--) {
		cout << v[i];
	}
	return 0;
}