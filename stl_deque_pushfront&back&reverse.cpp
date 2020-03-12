//deque 예시 1,2
//앞뒤 삽입, 역으로 출력

#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> dq;

	for (int i = 0; i < 5; i++) {
		dq.push_back((i + 1) * 10);
	}

	//iterator 선언
	deque<int>::iterator iter;

	//[default 출력]
	cout << "[Default] : ";
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	//[test1] : 앞 뒤 삽입
	cout << "[Test1] push_front & end : ";

	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(100);
	dq.push_back(200);

	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	//[test2] : 역으로 출력
	cout << "[Test2] reverse_iterator : ";

	deque<int>::reverse_iterator rIter;

	for (rIter = dq.rbegin(); rIter != dq.rend(); rIter++) {
		cout << *rIter << " ";
	}
	cout << endl;

	return 0;
}