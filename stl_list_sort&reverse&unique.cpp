//list ���� 3,4
//unique�� sort

#include <iostream>
#include <list>
#include <functional>
#include <string>
using namespace std;


int main() {
	list<string> lt;

	lt.push_back("b");
	lt.push_back("c");
	lt.push_back("a");
	lt.push_back("q");
	lt.push_back("a");
	lt.push_back("a");
	lt.push_back("a");
	lt.push_back("k");
	lt.push_back("j");
	lt.push_back("p");
	lt.push_back("q");
	lt.push_back("o");
	lt.push_back("e");
	lt.push_back("a");
	lt.push_back("a");

	list<string>::iterator iter;

	cout << "orign)";
	for (iter = lt.begin(); iter != lt.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	//uniue��� �Լ������ؼ� �پ��ִ� ���� ����
	cout << "unique)";
	lt.unique();
	for (iter = lt.begin(); iter != lt.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	//sort �⺻���� ���������� ���ؼ�
	//string�� ���������� ����
	cout << "sort 1) ";
	lt.sort();
	for (iter = lt.begin(); iter != lt.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	//sort ��������
	cout << "sort 2) ";
	lt.reverse();
	for (iter = lt.begin(); iter != lt.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	return 0;
}