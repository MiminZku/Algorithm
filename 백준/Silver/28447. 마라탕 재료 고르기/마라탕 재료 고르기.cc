#include <iostream>

using namespace std;

int n, k;
int mat[10][10];
int ans = -100000;
int selected[10];

void Recur(int level, int start)
{
	if (level == k)
	{
		int sum = 0;
		for (int i = 0; i < level; ++i)
		{
			for (int j = i; j < level; ++j)
			{
				sum += mat[selected[i]][selected[j]];
			}
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = start; i < n; ++i)
	{
		selected[level] = i;
		Recur(level + 1, i + 1);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	Recur(0, 0);

	cout << ans << endl;
}