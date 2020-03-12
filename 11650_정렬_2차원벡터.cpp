#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include<algorithm>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> arr;
	arr.assign(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i][0] << " " << arr[i][1] << "\n";
	}
	return 0;
}
