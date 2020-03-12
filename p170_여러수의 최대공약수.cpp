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
	cout << "�ִ�����(��Ŭ���� ȣ����)\n";
	cout << "�� �ڸ��� ? : ";
	int n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "input : ";
		cin >> a[i];
	}
	cout << "�ִ������� : " << gcd_array(a,n) << endl;
	return 0;
}
