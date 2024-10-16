#include <iostream>
#include <memory.h>

using namespace std;

int n, m;
int mat[1000][1000];

int dy[] = { 1, 0, 0 };
int dx[] = { 0, -1, 1 };

int dp[1000][1000][3];

int Recur(int y, int x, int dir)
{
	if (y == n - 1 && x == m - 1)
	{
		return mat[y][x];
	}

	if (dp[y][x][dir] != -1) return dp[y][x][dir];

	int temp = -100000000;
	for (int i = 0; i < 3; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)	continue;
		if (1 == dir && 2 == i) continue;
		if (2 == dir && 1 == i) continue;
		temp = max(temp, Recur(ny, nx, i) + mat[y][x]);
	}
	return dp[y][x][dir] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout<< Recur(0, 0, 0) << endl;
}