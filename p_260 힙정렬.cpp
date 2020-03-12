#include<iostream>
using namespace std;
//힙 정렬 프로그램

static void downheap(int a[], int left, int right) {
	int temp = a[left];						//루트
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {
		int cl = parent * 2 + 1;			//왼쪽 자식
		int cr = cl + 1;					//오른쪽 자식
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
		if (temp >= a[child]) break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

//힙정렬 함수
void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) {	//downheap 함수를 사용하여 배열 a를 힙으로 만듦
		downheap(a, i, n - 1);			
	}
	for (i = n - 1; i >= 0; i--) {			//루트(a[0])에 있는 가장 큰 값을 빼내어 배열 마지막
		swap(a[0], a[i]);					//요소와 바꾸고 배열의 나머지 부분을 다시 힙으로
		downheap(a, 0, i - 1);				//만드는 과정을 반복하여 정렬을 수행
	}
}

int main() {
	int i, nx;
	int *x;

	cout << "힙정렬" << endl;
	cout << "요소 개수 : ";
	cin >> nx;
	x = new int[nx];
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		cin >> x[i];
	}
	heapsort(x, nx);				//배열 x 힙정렬
	cout << "오름차순정렬\n";
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}

	delete[] x;
	return 0;
}