#include <iostream>
#include <memory.h>

#define ll long long

using namespace std;

int n;
ll dp[101][10][1024];
int d[] = { -1, 1 };
//int path[100];

ll Recur(int level, int prev, int bitmask)
{
	if (level == n)
	{
		if (0b1111111111 == bitmask)
		{
			return 1;
		}
		return 0;
	}

	if (dp[level][prev][bitmask] != -1) return dp[level][prev][bitmask];

	ll ret = 0;
	for (int i = 0; i < 2; ++i)
	{
		int cur = prev + d[i];
		if (cur < 0 || cur > 9) continue;
		//path[level] = cur;
		ret += Recur(level + 1, cur, bitmask | (1 << cur)) % 1'000'000'000;
	}
	return dp[level][prev][bitmask] = ret % 1'000'000'000;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	memset(dp, -1, sizeof(dp));

	ll ans = 0;
	for (int i = 1; i < 10; ++i)
	{
		//path[0] = i;
		ans += Recur(1, i, (1 << i)) % 1'000'000'000;
	}
	cout << ans % 1'000'000'000 << endl;
}