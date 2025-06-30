#include <iostream>
#include <memory.h>

using namespace std;

int c, n;
pair<int, int> arr[20];
int memo[1010];

int Recur(int clients)
{
	if (clients >= c)
	{
		return 0;
	}

	if (memo[clients] != -1)
	{
		return memo[clients];
	}

	int ret = 1'000'000'000;
	for (int i = 0; i < n; ++i)
	{
		ret = min(ret, Recur(clients + arr[i].second) + arr[i].first);
	}

	return memo[clients] = ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> c >> n;
	for (int i = 0, a, b; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	cout << Recur(0) << endl;
}