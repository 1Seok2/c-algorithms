//stack ±¸Çö
#include <iostream>
#include <string>
using namespace std;

int a[10];
int Top = -1;

void push(int x) {
	a[Top + 1] = x;
	Top++;
}

void pop() {
	if (Top < 0) {
		cout << "-1" << endl;
		return;
	}
	cout << a[Top] << endl;
	Top--;
}

void size() {
	cout << Top + 1 << endl;
}

void empty() {
	if (Top < 0) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
}

void top() {
	if (Top < 0) {
		cout << "-1" << endl;
		return;
	}
	cout << a[Top] << endl;
}

int main() {
	int n;
	cin >> n;
	string c;
	int p;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == "push") {
			cin >> p;
			push(p);
		}
		else if (c == "top") {
			top();
		}
		else if (c == "size") {
			size();
		}
		else if (c == "empty") {
			empty();
		}
		else if (c == "pop") {
			pop();
		}
		else break;
	}
	return 0;
}