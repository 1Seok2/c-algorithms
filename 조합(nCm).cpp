#include<iostream>

#define MAX 8
using namespace std;

int Arr[MAX];
int m,n;
bool Select[MAX];

void Print()
{
	for (int i = 0; i < n; i++)
	{
		if (Select[i] == true)
		{
			cout << Arr[i] << " ";
		}
	}
	cout << endl;

}

void DFS(int Idx, int Cnt)
{
	if (Cnt == m)
	{
		Print();
		return;
	}

	for (int i = Idx; i < n; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;

		DFS(i, Cnt + 1);
		Select[i] = false;
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		Arr[i] = i + 1;
	}

	DFS(0, 0);
	return 0;
}