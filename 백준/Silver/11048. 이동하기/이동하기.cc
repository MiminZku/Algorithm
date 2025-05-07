#include <iostream>
#include <memory.h>

using namespace std;

int n, m;
int mat[1001][1001];
int memo[1001][1001];

int dr[] = { 1, 0, 1 };
int dc[] = { 0, 1, 1 };

int Recur(int row, int col)
{
	if (row == n && col == m)
	{
		return mat[row][col];
	}

	if (memo[row][col] != -1)
	{
		return memo[row][col];
	}

	int ret = 0;
	for (int i = 0; i < 3; ++i)
	{
		int nr = dr[i] + row;
		int nc = dc[i] + col;
		if (nr > n || nc > m)	continue;
		ret = max(ret, mat[row][col] + Recur(nr, nc));
	}

	return memo[row][col] = ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout << Recur(1, 1) << endl;
}