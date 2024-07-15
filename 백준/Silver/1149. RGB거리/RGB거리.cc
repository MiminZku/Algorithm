#include <iostream>

using namespace std;

int n;
int arr[1000][3];
int dp[1000][3];

int Recur(int idx, int color)
{
	if (n == idx)
	{
		return 0;
	}

	if (1000000 != dp[idx][color])	return dp[idx][color];
	
	for (int i = 0; i < 3; ++i)
	{
		if (i == color)	continue;
		dp[idx][color] = min(dp[idx][color], arr[idx][color] + Recur(idx + 1, i));
	}
	return dp[idx][color];
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		for (int j = 0; j < 3; ++j) dp[i][j] = 1000000;
	}

	cout << min(Recur(0, 0), min(Recur(0, 1), Recur(0, 2))) << endl;
}