#include <iostream>
#include <memory.h>

using namespace std;

int t;
int n, k;
char mat[50][50];
int dp[50][50][3][4];

int dx[] = { 0, 0, 1 };
int dy[] = { 0, 1, 0 };

int Recur(int r, int c, int dir, int cnt)
{
	if (cnt > k)	return 0;
	if (c == n - 1 && r == n - 1)
	{
		return 1;
	}

	if (dp[r][c][dir][cnt] != -1)	return dp[r][c][dir][cnt];

	int ret = 0;
	for (int i = 1; i <= 2; ++i)
	{
		int ny = dy[i] + r;
		int nx = dx[i] + c;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
		if (mat[ny][nx] == 'H')	continue;
		ret += Recur(ny, nx, i, dir ? (cnt + (dir != i)) : 0);
	}
	return dp[r][c][dir][cnt] = ret;
}


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mat[i][j];
			}
		}
		cin.ignore();

		cout << Recur(0, 0, 0, 0)<< '\n';
	}
}