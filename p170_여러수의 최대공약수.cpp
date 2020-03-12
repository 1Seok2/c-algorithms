	#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int gcd_array(const int a[], int n) {
	int gc= gcd(a[0], a[1]);
	for (int i = 2; i < n; i++) {
		gc = gcd(gc, a[i]);
	}
	return gc;
}

int main(){
	int *a;
	cout << "최대공약수(유클리드 호제법)\n";
	cout << "몇 자리수 ? : ";
	int n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "input : ";
		cin >> a[i];
	}
	cout << "최대공약수는 : " << gcd_array(a,n) << endl;
	return 0;
}
