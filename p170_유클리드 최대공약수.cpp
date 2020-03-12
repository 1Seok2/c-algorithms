#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main(){
	int x, y;
	cout << "최대공약수(유클리드 호제법)\n";
	cout << "input : ";
	cin >> x;
	cout << "input : ";
	cin >> y;
	cout << "최대공약수는 : " << gcd(x, y) << endl;
	return 0;
}
