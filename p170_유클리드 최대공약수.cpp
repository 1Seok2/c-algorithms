#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main(){
	int x, y;
	cout << "�ִ�����(��Ŭ���� ȣ����)\n";
	cout << "input : ";
	cin >> x;
	cout << "input : ";
	cin >> y;
	cout << "�ִ������� : " << gcd(x, y) << endl;
	return 0;
}
