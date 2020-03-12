#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string arp = "abcdefghijklmnopqrstuvwxyz";
	string str;
	cin >> str;
	int anum[26];
	fill_n(anum, 26, 0);
	for (int i = 0; i < str.length(); i++) {
		if ((int)str[i] < 97) str[i] = (char)((int)str[i] + 32);
		if (!(arp.find(str[i]) == string::npos)) {
			anum[arp.find(str[i])]++;
		}
	}
	int max = 0;
	int cor = 0;
	int idx = 0;
	for (int i = 0; i < 26; i++) {
		if (anum[i] > max) {
			max = anum[i];
			cor = 0;
			idx = i;
		}
		else if (anum[i] == max) cor++;
	}
	if (cor > 0) cout << "?\n";
	else cout << (char)(idx+65) << "\n";
	return 0;
}