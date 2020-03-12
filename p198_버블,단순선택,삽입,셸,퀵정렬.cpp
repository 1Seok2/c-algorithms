#include <iostream>
#include <cmath>
#include <queue>
#include<stack>
using namespace std;

//버블정렬
void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
		}
	}
}

//버블정렬2 : 교환횟수에 따라 작업을 멈춤
void bubble2(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;						//패스에서 시도한 교환 횟수
		for (j = n-1; j > i; j--) {			//			ㅡ
			if (a[j - 1] > a[j]) {			//
				swap(a[j - 1], a[j]);		//		   패스
				exchg++;					//
			}								//
		}									//			ㅡ
		if (exchg == 0) break;				// 교환이 수행되지 않았다면 정렬 멈춤
	}
}

//버블정렬3 : 스캔범위를 제한함
void bubble3(int a[], int n) {
	int k = 0;								//a[k]보다 앞쪽의 요소는 정렬을 마친 상태
	while (k < n - 1) {
		int j;
		int last = n - 1;					//마지막으로 교환을 수행한 위치를 저장
		for (j = n - 1; j > k; j--) {
			if (a[j - 1]> a[j]) {
				swap(a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
	}
}

//단순 선택정렬
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

//단순 삽입 정렬
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
/*========== 위의 시간복잡도는 O(n2) -> 효율 안좋음 =============*/

//셸 정렬 함수 : 정렬횟수는 늘지만 전체적으로 요소 이동횟수가 감소로 효율적.
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

//셸 정렬 함수2 : (h=..., 13, 4, 1)
void shell2(int a[], int n) {
	int i, j, h;
	for (h = 1; h < n / 9; h = h * 3 + 1)
	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int tmp = a[i];//움직이게될 값
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];//높은 idx에 큰 값넣음
			}
			a[j + h] = tmp;//j가 음수가 돼서 빠져나와서 j+h
		}
	}
}

//퀵 // 배열의 분할 과정을 출력하는 퀵 정렬 프로그램
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

//퀵정렬
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