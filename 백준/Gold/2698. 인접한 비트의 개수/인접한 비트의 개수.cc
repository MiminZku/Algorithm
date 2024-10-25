#include <iostream>

using namespace std;

int t;
int dp[101][101][2];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> t;
	
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i <= 100; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			dp[i][j][1] = dp[i - 1][j][0];
			if (j > 0)
			{
				dp[i][j][1] += dp[i - 1][j - 1][1];
			}

			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
		}
	}

	int n, k;
	while (t--)
	{
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << '\n';
	}

}