#include <iostream>
#include <memory.h>

using namespace std;

int n;
int mat[20][20];
int dp[20][20][3];

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

int Recur(int r, int c, int dir)	// dir : 0 = 가로, 1 = 세로, 2 = 대각선
{
	if (r < 1 || c < 1 || r > n || c > n)	return 0;
	if (r == n && c == n)
	{
		return 1;
	}

	if (dp[r][c][dir] != -1)	return dp[r][c][dir];

	int temp = 0;
	for (int i = 0; i < 3; ++i)
	{
		int nr = dx[i] + r;
		int nc = dy[i] + c;
		if (nr > n || nc > n)	continue;
		if (mat[nr][nc])	continue;
		if (i == 0 && dir == 1)	continue;
		if (i == 1 && dir == 0)	continue;
		if (i == 2 && (mat[nr - 1][nc] || mat[nr][nc - 1]))	continue;
		temp += Recur(nr, nc, i);
	}
	return dp[r][c][dir] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout << Recur(1, 2, 0) << endl;
}