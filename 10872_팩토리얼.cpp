#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int sum = 1;
int factorial(int n) {
	if (n > 2)
		n *= factorial(n - 1);
	return n;
}
int main(void) {
	int num, result = 1;
	cin >> num;
	if (num != 0)
		result = factorial(num);
	cout << result;
	return 0;
}