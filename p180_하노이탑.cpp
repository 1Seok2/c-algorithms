#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

/* ����[1] ~ ����[num]�� x��տ��� y������� �ű�*/
void move(int num, int x,int y) {
	if (num > 1) {
		move(num - 1, x, 6 - x - y); // �׷��� ���� ��տ��� �߰� �������
	}
	printf("����[%d]��(��) %d ��տ��� %d ������� �ű�\n", num, x, y);//�ٴ� ������ ��ǥ �������
	if (num > 1) {
		move(num - 1, 6 - x - y, y); //�׷��� �߰� ��տ��� ��ǥ �������
	}
}

int main() {
	int n; //������ ����
	cout << "�ϳ���ž�� ���� ���� : ";
	cin >> n;
	move(n, 1, 3);
	return 0;
}