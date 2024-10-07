#include<iostream>
#include<algorithm>

using namespace std;

int N, M, ans, totalCost;
int memory[101], cost[101];
int dp[101][10001];  // dp[i][j] : i번째 앱까지, j비용을 소모해서 얻을 수 있는 최대 메모리

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> memory[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		totalCost += cost[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= totalCost; j++)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= totalCost; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << endl;
			break;
		}
	}
}