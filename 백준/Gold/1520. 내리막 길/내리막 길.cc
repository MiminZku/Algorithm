#include <iostream>
#include <memory.h>

using namespace std;

int m, n;
int mat[500][500];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dp[500][500];

int Recur(int r, int c)
{
	if (r == m - 1 && c == n - 1)
	{
		return 1;
	}
	if (dp[r][c] >= 0)	return dp[r][c];

	int temp = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || nc < 0 || nr >= m || nc >= n)	continue;
		if (mat[nr][nc] >= mat[r][c]) continue;
		temp += Recur(nr, nc);
	}

	return dp[r][c] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> m >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}
	cout << Recur(0, 0) << endl;
}