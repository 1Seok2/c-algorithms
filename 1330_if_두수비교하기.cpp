#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int a, b;
	cin >> a >> b;
	if (a<-10000 || b<-10000 || a>10000 || b>10000) return -1;

	if (a > b) cout << ">" << endl;
	else if (a < b) cout << "<" << endl;
	else cout << "==" << endl;

	return 0;
}