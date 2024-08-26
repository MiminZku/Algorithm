#include <iostream>

using namespace std;

int n, m;
int mat[335][335];
int cumulativeSum[335][335];

int GetSubMatrixSum(int r1, int c1, int r2, int c2)
{
	return cumulativeSum[r2][c2]
		- cumulativeSum[r2][c1 - 1]
		- cumulativeSum[r1 - 1][c2]
		+ cumulativeSum[r1 - 1][c1 - 1];
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	cin.ignore();
	char ch;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> ch;
			mat[i][j] = ch - '0' ? 0 : 1;
			cumulativeSum[i][j] =
				mat[i][j] + cumulativeSum[i - 1][j] + cumulativeSum[i][j - 1] - cumulativeSum[i - 1][j - 1];
		}
	}

	int ans = 0;
	// 열 2개 선택
	for (int i = 1; i <= m; ++i)
	{
		for (int j = i; j <= m; ++j)
		{
			// 행을 따라 내려가면서
			int cnt = 0;
			for (int k = 1; k <= n; ++k)
			{
				int sum = GetSubMatrixSum(k, i, k, j);
				if (j - i + 1 == sum)
				{
					cnt += sum;
					ans = max(ans, cnt);
				}
				else
				{
					cnt = 0;
				}
			}
		}
	}
	cout << ans << endl;
}