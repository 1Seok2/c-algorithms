#include <iostream>
#include <string>
#include<queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 666 << "\n";
		return 0;
	}
	int num = 0;
	for (int i = 666; i < MAX; i++) {
		int temp = i;
		int sixcount = 0;
		while (temp) {
			if (temp % 10 == 6) {
				sixcount++;
				temp /= 10;
				if (sixcount == 3) {
					num++;
					if (num == n) {
						cout << i << "\n";
						return 0;
					}
				}
			}
			else {
				sixcount = 0;

				temp /= 10;
			}
		}
		
	}

	return 0;
}