#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[2001];
int m;
int dp[2001][2001];

bool Recur(int s, int e)
{
	if (s > e)	return true;
	if (s == e) return true;

	if (dp[s][e] != -1)	return dp[s][e];

	if (arr[s] == arr[e])
	{
		return dp[s][e] = Recur(s + 1, e - 1);
	}
	return dp[s][e] = false;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> arr[i];
	memset(dp, -1, sizeof(dp));

	cin >> m;
	int s, e;
	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		cout << Recur(s, e) << '\n';
	}
}