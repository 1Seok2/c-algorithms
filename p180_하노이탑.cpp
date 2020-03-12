#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

/* 원반[1] ~ 원반[num]을 x기둥에서 y기둥으로 옮김*/
void move(int num, int x,int y) {
	if (num > 1) {
		move(num - 1, x, 6 - x - y); // 그룹을 시작 기둥에서 중간 기둥으로
	}
	printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", num, x, y);//바닥 원반을 목표 기둥으로
	if (num > 1) {
		move(num - 1, 6 - x - y, y); //그룹을 중간 기둥에서 목표 기둥으로
	}
}

int main() {
	int n; //원반의 개수
	cout << "하노이탑의 원반 개수 : ";
	cin >> n;
	move(n, 1, 3);
	return 0;
}