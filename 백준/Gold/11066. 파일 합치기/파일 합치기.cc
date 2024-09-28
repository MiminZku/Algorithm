#include <iostream>

using namespace std;

int t;
int k;
int fileSize[500][500];
int dp[500][500];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> fileSize[i][i];
		}

		for (int i = k - 1; i >= 0; --i)
		{
			for (int j = i; j < k; ++j)
			{
				if (i == j)	continue;
				
				//dp[i][i] + dp[i + 1][j];
				//dp[i][i + 1] + dp[i + 2][j];
				//// . . .
				//dp[i][j - 2] + dp[j - 1][j];
				//dp[i][j - 1] + dp[j][j];

				int minCost = 500000000;
				int size = 500000000;
				for (int l = i; l < j; ++l)
				{
					int newFileSize = fileSize[i][l] + fileSize[l+1][j];
					int cost = dp[i][l] + dp[l + 1][j] + newFileSize;
					if (cost <= minCost)
					{
						minCost = cost;
						size = min(size, newFileSize);
					}
				}
				dp[i][j] = minCost;
				fileSize[i][j] = size;
			}
		}
		cout << dp[0][k - 1] << '\n';
	}
}