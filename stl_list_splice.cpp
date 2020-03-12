//list 예시 5
//splice

#include <iostream>
#include <list>
#include <functional>
#include <string>
using namespace std;


int main() {
	list<string> lt1;

	lt1.push_back("a");
	lt1.push_back("b");
	lt1.push_back("c");
	lt1.push_back("d");
	lt1.push_back("e");

	list<string> lt2;
	lt2.push_back("X");
	lt2.push_back("Y");
	lt2.push_back("Z");

	list<string>::iterator iter;

	cout << "[lt1] orign) ";
	for (iter = lt1.begin(); iter != lt1.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "[lt2] orign) ";
	for (iter = lt2.begin(); iter != lt2.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	////////////////////////////////////////
	iter = lt2.begin();
	iter++;

	//lt2의 iter부분부터 lt1을 잘러서 붙임

	lt2.splice(iter, lt1);
	cout << "[lt1] splice) ";
	for (iter = lt1.begin(); iter != lt1.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "lt1.size() : " << lt1.size() << endl;
	cout << endl << endl;

	cout << "[lt2] splice) ";
	for (iter = lt2.begin(); iter != lt2.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "lt2.size() : " << lt2.size() << endl;
	


	return 0;
}