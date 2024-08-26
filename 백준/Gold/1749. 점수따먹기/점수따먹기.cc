#include <iostream>

using namespace std;

int n, m;
int mat[202][202];
int cumulativeSum[202][202];

int GetSubMatrixSum(int r1, int c1, int r2, int c2)
{
	return cumulativeSum[r2][c2] 
			- cumulativeSum[r2][c1 - 1] 
			- cumulativeSum[r1- 1][c2] 
			+ cumulativeSum[r1 - 1][c1 - 1];
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	int maxNum = -10000;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> mat[i][j];
			maxNum = max(maxNum, mat[i][j]);
			cumulativeSum[i][j] += 
				cumulativeSum[i - 1][j] + cumulativeSum[i][j - 1] + mat[i][j] - cumulativeSum[i - 1][j - 1];
		}
	}

	int ans = maxNum;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = i; j <= m; ++j)
		{
			int sum = 0;
			for (int k = 1; k <= n; ++k)
			{
				int temp = GetSubMatrixSum(k, i, k, j);
				sum += temp;
				if (sum < 0)
				{
					sum = 0;
					continue;
				}
				ans = max(ans, sum);
			}
		}
	}
	cout << ans << endl;
}