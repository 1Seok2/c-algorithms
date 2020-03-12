#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string arp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,
							7,7,7,7,8,8,8,9,9,9,9 };
	string str;
	cin >> str;
	int time = 0;
	for (int i = 0; i < str.length(); i++) {
		time += num[arp.find(str[i])]+1;
	}
	cout << time << "\n";
	return 0;
}