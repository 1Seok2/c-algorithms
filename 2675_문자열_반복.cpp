#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	string str;
	string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:";
	int *Re = new int[testcase];
	
	for (int i = 0; i < testcase; i++) {
		string cpyStr;
		cin >> Re[i] >> str;
		for (int j = 0; j < str.length(); j++) {
			if (alpha.find(str[j]) == string::npos) {
				return -1;
			}
			else {
				for (int k = 0; k < Re[i]; k++) {
					cpyStr += str[j];
				}
			}
		}
		cout << cpyStr << endl;
	}
	return 0;
}