#include<iostream>
#include<cstring>
using namespace std;

void SelectionSort(int* a, const int n);
int BinarySearch(int* a, const int x, const int n);
int BinarySearch(int* a, const int x, const int left, const int right);
void Permutations(char* b, const int k, const int m);

int main() {
	int a[5] = { 0,3,2,6,4 };
	SelectionSort(a, 5);

	char b[3] = { 'b', 'v', 'd' };
	int length = strlen(b);

	Permutations(b, 1, length);

	for (int i = 0; i < 5; i++) {
		cout << "SelectionSort : " << a[i] << " ";
		cout << endl;
	}
	int m1 = BinarySearch(a, 3, 0, 4);
	int m2 = BinarySearch(a, 1, 0, 4);

	if (m1 == -1) {
		cout << "m1 didnt have founded\n";
	}
	else cout << "m1 : " << m1 << endl;

	if (m2 == -1) {
		cout << "m2 didnt have founded\n";
	}
	else cout << "m2 : " << m1 << endl;

	cout << "B";
	for (int i = 0; i < 3; i++) {
		cout << b[i];
	}
	cout << endl;
	return 0;
}

void SelectionSort(int* a, const int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		for (int k = i+1; k < n; k++) {
			if (a[k] < a[j]) j = k;
		}
		swap(a[i], a[j]);
	}
}

int BinarySearch(int* a, const int x, const int n) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (x < a[middle]) right = middle - 1;
		else if (x > a[middle]) left = middle + 1;
		else return middle;
	}
	return -1;
}

int BinarySearch(int* a, const int x, const int left, const int right) {
	if (left <= right) {
		int middle = (left + right) / 2;
		if (x < a[middle]) return BinarySearch(a, x, left, middle - 1);
		else if (x > a[middle]) return BinarySearch(a, x, middle + 1, right);
		return middle;
	}
	return -1;
}

void Permutations(char* b, const int k, const int m) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << b[i] << " ";
		cout << endl;
	}
	else {
		for (int i = k + 1; i < m; i++) {
			swap(b[k], b[i]);
			Permutations(b, k + 1, m);
			swap(b[k], b[i]);
		}
	}
}