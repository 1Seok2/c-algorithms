#include <iostream>

using namespace std;


void upArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

int binarySearch(int a[], int n, int find) {
	int left = 0, right = n - 1;
	do {
		int center = (left + right) / 2;
		if (a[center] == find) {
			while (a[center - 1] == a[center]) {
				center--;
			}
			return center;
		}
		else if (a[center] < find) {
			left = center + 1;
		}
		else {
			right = center - 1;
		}
	} while (left <= right);

	return -1;
}

int main(void) {
	int n;
	cout << "몇자리의 수 입력 : ";
	cin >> n;
	cout << endl;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		printf("a[%d] 입력 : ",i);
		cin >> a[i];
	}
	cout << endl;
	

	cout << "찾을 수 : ";
	int findNum;
	cin >> findNum;
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j) {
				cout << "* " << endl;
				break;
			}
			cout << "  ";
		}
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		if (findNum == a[i]) {
			cout << "Find\n";
			delete[] a;
			return 0;
		}
	}
	cout << "NotFind\n";
	*/
	upArr(a, n);
	cout << endl;
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	cout<<"index : "<<binarySearch(a, n, findNum);
	delete[] a;

	return 0;
}
