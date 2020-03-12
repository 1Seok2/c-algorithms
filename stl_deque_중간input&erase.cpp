//deque ���� 3,4
//�߰�����, ����, ���
//offset out of range ����(49��)

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<string> dq;

	dq.push_front("Dok2");
	dq.push_back("ZICO");
	dq.push_front("Tiger_JK");

	cout << "[Default]" << endl;
	deque<string>::iterator iter;
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "[Test3] insert(conIter ++ �ι�, 2, INSERT)\n";
	deque<string>::const_iterator conIter = dq.begin();
	conIter += 2;
	dq.insert(conIter, 2, "INSERT");
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "[Test4] dq.end()�� ���� erase, erase" << endl;
	conIter = dq.end();
	//end�� �� �������� "����"�� ����Ű�Ƿ� �� ��������
	//����Ű���� �ѹ� --����
	conIter--;
	//�ѹ���--;
	conIter--;


	dq.erase(conIter);
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;


	dq.erase(conIter);
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;

	cout << "[Test5-1]dq.at(i) : ";
	deque<string>::size_type i;
	for (int i = 0; i < dq.size(); i++) {
		cout << dq.at(i) << " ";
	}
	cout << endl;


	cout << "[Test5-2] dq[i] : ";
	for (i = 0; i < dq.size(); i++) {
		cout << dq[i] << " ";
	}
	cout << endl;

	return 0;
}