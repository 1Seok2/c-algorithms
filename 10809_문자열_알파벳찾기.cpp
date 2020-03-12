#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	string arr = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	for (int i = 0; i < arr.length(); i++) {
		if (s.find(arr[i]) == string::npos) {
			cout << -1 << " ";
		}
		else {
			cout << s.find(arr[i]) << " ";
			continue;
		}
	}
	return 0;
}