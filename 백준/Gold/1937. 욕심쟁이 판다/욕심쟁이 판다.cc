#include <iostream>
#include <memory.h>

using namespace std;

int n;
int mat[500][500];
int dp[500][500];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int Recur(int r, int c)
{
	if (dp[r][c] != -1)	return dp[r][c];
	
	int temp = 0;
	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (mat[nr][nc] <= mat[r][c]) continue;
		temp = max(temp, Recur(nr, nc));
	}
	return dp[r][c] = temp + 1;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans = max(ans, Recur(i, j));
		}
	}
	cout << ans << endl;
}