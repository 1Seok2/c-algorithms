#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> vec = { "c=", "c-", "dz=", "d-",
						"lj", "nj", "s=", "z=", };
	int idx = 0;
	string str;
	cin >> str;
	for (int i = 0; i < vec.size(); i++) {
		idx = str.find(vec[i]);
		for (; idx != string::npos; idx = s.find(vec[i])) {
			str.replace(idx, vec[i].lengty(), "@");
		}
		cout << str.length();
	}
	return 0;
}