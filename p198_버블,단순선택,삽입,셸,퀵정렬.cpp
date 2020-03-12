#include <iostream>
#include <cmath>
#include <queue>
#include<stack>
using namespace std;

//��������
void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
		}
	}
}

//��������2 : ��ȯȽ���� ���� �۾��� ����
void bubble2(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;						//�н����� �õ��� ��ȯ Ƚ��
		for (j = n-1; j > i; j--) {			//			��
			if (a[j - 1] > a[j]) {			//
				swap(a[j - 1], a[j]);		//		   �н�
				exchg++;					//
			}								//
		}									//			��
		if (exchg == 0) break;				// ��ȯ�� ������� �ʾҴٸ� ���� ����
	}
}

//��������3 : ��ĵ������ ������
void bubble3(int a[], int n) {
	int k = 0;								//a[k]���� ������ ��Ҵ� ������ ��ģ ����
	while (k < n - 1) {
		int j;
		int last = n - 1;					//���������� ��ȯ�� ������ ��ġ�� ����
		for (j = n - 1; j > k; j--) {
			if (a[j - 1]> a[j]) {
				swap(a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
	}
}

//�ܼ� ��������
void selection(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

//�ܼ� ���� ����
void insertion(int a[], int n) {
	int i, j;
	for(i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = tmp;
	}
}
/*========== ���� �ð����⵵�� O(n2) -> ȿ�� ������ =============*/

//�� ���� �Լ� : ����Ƚ���� ������ ��ü������ ��� �̵�Ƚ���� ���ҷ� ȿ����.
void shell(int a[], int n) {
	int i, h, j;
	for (h = n / 2; h > 0; h /= 2) {
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
			}
			a[j + h] = tmp;
		}
	}
}

//�� ���� �Լ�2 : (h=..., 13, 4, 1)
void shell2(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int tmp = a[i];//�����̰Ե� ��
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];//���� idx�� ū ������
			}
			a[j + h] = tmp;//j�� ������ �ż� �������ͼ� j+h
		}
	}
}

//�� // �迭�� ���� ������ ����ϴ� �� ���� ���α׷�
void quick(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];

	int i;
	printf("a[%d]~a[%d] : {", left, right);
	for (i = left; i < right; i++) {
		printf("%d ",a[i]);
	}
	printf("%d}\n", a[right]);

	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

//������
void quick1(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	do {
		while (a[pl] < x)pl++;
		while (a[pr] > x)pr--;
		if (pl <= pr) {
			swap(a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main() {
	int n = 7;
	int a[7] = { 22,5,11,32,120,68,70 };

	shell2(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	return 0;
}