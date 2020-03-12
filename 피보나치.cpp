#include <iostream>
using namespace std;

void sumPb(int a[], int len, int &count);

int main() {
	int n;
	cin >> n;
	if (n < 0 || n>20) exit(0);
	int *pb = new int[n+2];
	pb[0] = 0;
	pb[1] = 1;
	int count = 0;
	sumPb(pb, n, count);
	cout << pb[n] << endl;
	delete pb;
	return 0;
}

void sumPb(int a[], int len, int &count) {
	a[count + 2] = a[count + 1] + a[count];
	count++;
	if (count < len) sumPb(a, len, count);
}