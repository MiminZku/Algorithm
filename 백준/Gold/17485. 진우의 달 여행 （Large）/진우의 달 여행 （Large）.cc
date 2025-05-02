#include <iostream>
#include <memory.h>

using namespace std;

int n, m;
int mat[1000][1000];
int memo[1000][1000][3];

int dx[] = { -1, 0, 1 };

int Recur(int y, int x, int prevDir)
{
	if (y == n)
	{
		return 0;
	}

	if (prevDir != -1 && memo[y][x][prevDir] != -1)
	{
		return memo[y][x][prevDir];
	}

	int ret = 1'000'000;
	for (int dir = 0; dir < 3; ++dir)
	{
		if (dir == prevDir)	continue;

		int nx = dx[dir] + x;
		if (nx < 0 || nx >= m)	continue;

		ret = min(ret, mat[y][x] + Recur(y + 1, nx, dir));
	}

	return memo[y][x][prevDir] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	int ans = 1'000'000;
	for (int i = 0; i < m; ++i)
	{
		ans = min(ans, Recur(0, i, -1));
	}

	cout << ans << endl;
}