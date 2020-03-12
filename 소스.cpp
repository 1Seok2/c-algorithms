#include<iostream>
#include<algorithm>

using namespace std;

int n, m, x, y, k;//m 가로, n세로
int** a;
int* togo;
int* temp;
int dice[6];

bool Test_way(int way,int xx, int yy) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		if (way == 1) {
			y--;
			return false;
		}
		else if (way == 2) {
			y++;
			return false;
		}
		else if (way == 3) {
			x++;
			return false;
		}
		else if (way == 4) {
			x--;
			return false;
		}
	}
	return true;
}

void dice_way(int way) {
	int temp[4];
	switch (way) {
	case 1://동
		y++;
		if (!Test_way(way, x, y)) break;;
		temp[0] = dice[0]; temp[1] = dice[2];
		temp[2] = dice[5]; temp[3] = dice[4];
		dice[0] = temp[3]; dice[2] = temp[0];
		dice[5] = temp[1];
		if (a[x][y] == 0) a[x][y] = dice[5];
		else {
			dice[5] = a[x][y];
			a[x][y] = 0;
		}
		dice[4] = temp[2];
		cout << dice[0] << "\n";
		break;
	case 2://서
		y--;
		if (!Test_way(way, x, y)) break;
		temp[0] = dice[0]; temp[1] = dice[4];
		temp[2] = dice[5]; temp[3] = dice[2];
		dice[0] = temp[3]; dice[2] = temp[2];
		dice[5] = temp[1];
		if (a[x][y] == 0) a[x][y] = dice[5];
		else {
			dice[5] = a[x][y];
			a[x][y] = 0;
		}
		dice[4] = temp[0];
		cout << dice[0] << "\n";
		break;
	case 3://북
		x--;
		if (!Test_way(way, x, y)) break;
		temp[0] = dice[0]; temp[1] = dice[3];
		temp[2] = dice[5]; temp[3] = dice[1];
		dice[0] = temp[3]; dice[1] = temp[2];
		dice[5] = temp[1];
		if (a[x][y] == 0) a[x][y] = dice[5];
		else {
			dice[5] = a[x][y];
			a[x][y] = 0;
		}
		dice[3] = temp[0];
		cout << dice[0] << "\n";
		break;
	case 4://남
		x++;
		if (!Test_way(way, x, y)) break;
		temp[0] = dice[0]; temp[1] = dice[1];
		temp[2] = dice[5]; temp[3] = dice[3];
		dice[0] = temp[3]; dice[1] = temp[0];
		dice[5] = temp[1];
		if (a[x][y] == 0) a[x][y] = dice[5];
		else {
			dice[5] = a[x][y];
			a[x][y] = 0;
		}
		dice[3] = temp[2];
		cout << dice[0] << "\n";
		break;
	default:
		//cout << "NOT 1,2,3,4\n";
		break;
	}
	return;
}

int main() {
	cin >> n >> m >> x >> y >> k;
	a = new int*[n]; // nXm 배열
	togo = new int[k]; //동서남북 1243
	fill_n(dice, 6, 0); //주사위 처음 0
	for (int i = 0; i < n; i++) {
		a[i] = new int[m]; 
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> togo[i];
		if (togo[i] < 1 || togo[i]>4) togo[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		dice_way(togo[i]);
		//cout << dice[0] << "\n";
	}
	return 0;
}