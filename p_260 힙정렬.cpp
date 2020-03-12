#include<iostream>
using namespace std;
//�� ���� ���α׷�

static void downheap(int a[], int left, int right) {
	int temp = a[left];						//��Ʈ
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;			//���� �ڽ�
		int cr = cl + 1;					//������ �ڽ�
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
		if (temp >= a[child]) break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

//������ �Լ�
void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) {	//downheap �Լ��� ����Ͽ� �迭 a�� ������ ����
		downheap(a, i, n - 1);			
	}
	for (i = n - 1; i >= 0; i--) {			//��Ʈ(a[0])�� �ִ� ���� ū ���� ������ �迭 ������
		swap(a[0], a[i]);					//��ҿ� �ٲٰ� �迭�� ������ �κ��� �ٽ� ������
		downheap(a, 0, i - 1);				//����� ������ �ݺ��Ͽ� ������ ����
	}
}

int main() {
	int i, nx;
	int *x;

	cout << "������" << endl;
	cout << "��� ���� : ";
	cin >> nx;
	x = new int[nx];
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		cin >> x[i];
	}
	heapsort(x, nx);				//�迭 x ������
	cout << "������������\n";
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	delete[] x;
	return 0;
}