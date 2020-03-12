#include <iostream>
#include <cmath>
using namespace std;
//블랙잭. 카드의 합이 21 넘지않는 한도 내에서
//카드의 합을 최대한 크게 만드는 게임
int main() {
	int card_Num, almost_Sum;
	cin >> card_Num >> almost_Sum;
	if (card_Num < 3 || card_Num>100) exit(1);
	if (almost_Sum < 10 || almost_Sum>300000) exit(2);
	int *cards = new int[card_Num];
	for (int i = 0; i < card_Num; i++) {
		cin >> cards[i];
		if (cards[i] > 100000) exit(3);
	}

	int sum_num = card_Num
		*(card_Num - 1)*(card_Num - 2) / 6;

	int *Sums = new int[sum_num];
	int count = 0;
	int Top_sum = 0;
	int idx = 0;
	for (int i = 0; i < card_Num - 2; i++) {
		for (int j = i + 1; j < card_Num - 1; j++) {
			for (int k = j + 1; k < card_Num; k++) {
				Sums[count] = cards[i] + cards[j] + cards[k];
				if (count > 0) {
					if ((abs(almost_Sum - Sums[idx]) > abs(almost_Sum - Sums[count])) && Sums[count] < almost_Sum) {
						idx = count;
						Top_sum = Sums[idx];
					}
				}
				count++;
			}
		}
	}
	if (Top_sum == 0) exit(4);
	cout << Top_sum << endl;
	return 0;
}