#include <iostream>

using namespace std;

int n, m;
int mat[1111][1111];
int cumulativeSum[1111][1111];

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
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> mat[i][j];
			cumulativeSum[i][j] +=
				cumulativeSum[i - 1][j] + cumulativeSum[i][j - 1] + mat[i][j] - cumulativeSum[i - 1][j - 1];
		}
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << GetSubMatrixSum(x1, y1, x2, y2) << '\n';
	}
}