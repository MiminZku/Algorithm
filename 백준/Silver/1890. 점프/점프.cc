#include <iostream>
#include <memory.h>

using namespace std;

int n;
int mat[100][100];
long long memo[100][100];


long long Recur(int r, int c)
{	
	if (r == n - 1 && c == n - 1)
	{
		return 1;
	}
	if (mat[r][c] == 0)
	{
		return 0;
	}

	if (memo[r][c] != -1)
	{
		return memo[r][c];
	}

	int dr[] = { 0, mat[r][c] };
	int dc[] = { mat[r][c], 0 };

	long long ret = 0;
	for (int i = 0; i < 2; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= n || nc >= n)	continue;
		ret += Recur(nr, nc);
	}
	return memo[r][c] = ret;
}

int main()
{
	memset(memo, -1, sizeof(memo));
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	cout << Recur(0, 0) << endl;
}