#include<iostream>
#include<vector>

#define MAX 8
using namespace std;

int Arr[MAX];
bool Select[MAX];
vector<int> V;
int n, m;

void Print()
{
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
	cout << endl;
}

void DFS(int Cnt)
{
	if (Cnt == m)
	{
		Print();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (Select[i] == true) continue;
		Select[i] = true;
		V.push_back(Arr[i]);
		DFS(Cnt + 1);
		V.pop_back();
		Select[i] = false;
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		Arr[i] = i + 1;
	}

	DFS(0);
	return 0;
}