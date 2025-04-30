#include <iostream>
#include <memory.h>

using namespace std;

int n, k;
int value[100];
int memo[10001];

int Recur(int total)
{
	if (total == k)
	{
		return 0;
	}
	if (total > k)
	{
		return 1'000'000'000;
	}

	if (memo[total] != -1)
	{
		return memo[total];
	}

	int ret = 1'000'000'000;
	for (int i = 0; i < n; ++i)
	{
		ret = min(ret, Recur(total + value[i]) + 1);
	}
	return memo[total] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> value[i];
	}

	int ans = Recur(0);
	if (ans >= 1'000'000'000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << endl;
	}
}