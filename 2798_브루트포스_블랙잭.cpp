#include <iostream>
#include <cmath>
using namespace std;
//블랙잭. 카드의 합이 21 넘지않는 한도 내에서
//카드의 합을 최대한 크게 만드는 게임
int main() {
	int N, M;
	int A[100];
	cin >> N >> M;
	int result = 0;
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (A[i] + A[j] + A[k] <= M && M - (A[i] + A[j] + A[k]) < M - result)
				{
					result = A[i] + A[j] + A[k];
				}
			}
		}
	}
	cout << result;
}
