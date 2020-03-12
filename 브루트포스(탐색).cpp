#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int **mass = new int*[n];
	int *grade = new int[n];
	for (int i = 0; i < n; i++) {
		grade[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		mass[i] = new int[2];
		memset(mass[i], 0, sizeof(int) * 2);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> mass[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != i) {
				if (mass[i][0] < mass[j][0] && mass[i][1] < mass[j][1]) {
					grade[i]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << grade[i] << " ";
		delete[] mass[i];
	}
	delete[] mass;
	delete[] grade;
	
	
	return 0;
}


