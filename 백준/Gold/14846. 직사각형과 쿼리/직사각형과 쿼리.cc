#include <iostream>

using namespace std;

int n, q;
int cumulativeSum[335][335][11]; // cumulativeSum[i][j][k] : 0, 0 ~ i, j 부분 행렬 안의 k 의 개수

int GetSubMatrixSum(int r1, int c1, int r2, int c2)
{
	int ret = 0;

	for (int k = 1; k <= 10; ++k)
	{
		int cnt = cumulativeSum[r2][c2][k] - cumulativeSum[r2][c1 - 1][k] - cumulativeSum[r1 - 1][c2][k] + cumulativeSum[r1 - 1][c1 - 1][k];
		if (cnt > 0)	++ret;
	}

	return ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int l;
			cin >> l;
			for (int k = 1; k <= 10; ++k)
			{
				cumulativeSum[i][j][k] =
					(k == l) + cumulativeSum[i - 1][j][k] + cumulativeSum[i][j - 1][k] - cumulativeSum[i - 1][j - 1][k];
			}
		}
	}

	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << GetSubMatrixSum(x1, y1, x2, y2) << '\n';
	}
}