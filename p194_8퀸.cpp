#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int flag_a[8];			//�� �࿡ ���� ��ġ�ߴ��� üũ�ϴ� �迭
int flag_b[15];			//�밢�� /�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
int flag_c[15];			//�밢�� \�� ���� ��ġ�ߴ��� üũ�ϴ� �迭
int pos[8];				//�� ������ ���� ��ġ

//�� ������ ���� ��ġ�� ���
void print() {
	int i;
	for (i = 0; i < 8; i++) {
		cout << pos[i]<<" ";
	}
	cout<<endl;
}

//i������ �˸��� ��ġ�� ���� ��ġ
void set(int i) {
	int j;
	for (j = 0; j < 8; j++) {
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
			pos[i] = j;
			if (i == 7) { //��� ���� ��ġ�� ��ħ
				print();
			}
			else {
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main() {
	int i;
	for (i = 0; i < 8; i++) {
		flag_a[i] = 0;
	}
	for(i = 0; i < 15; i++) {
		flag_b[i] = flag_c[i] = 0;
	}
	set(0);
	return 0;
}