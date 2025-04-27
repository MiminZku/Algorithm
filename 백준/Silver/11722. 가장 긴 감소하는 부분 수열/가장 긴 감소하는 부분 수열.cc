#include <iostream>

using namespace std;

int n;
int arr[1000];
int memo[1000];

int LDS(int idx)
{
	if (idx == n)
	{
		return 0;
	}

	if (memo[idx] != 0)
	{
		return memo[idx];
	}

	int ret = 1;
	for (int i = idx + 1; i < n; ++i)
	{
		if (arr[idx] <= arr[i])	continue;
		
		ret = max(ret, 1 + LDS(i));
	}

	return memo[idx] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, LDS(i));
	}

	cout << ans << endl;
}