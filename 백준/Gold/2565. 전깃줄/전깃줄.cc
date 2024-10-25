#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n;
pair<int, int> arr[100];
int dp[100];

int LIS(int idx)
{
	if (dp[idx] != -1) return dp[idx];

	int tmp = 1;
	for (int i = idx + 1; i < n; ++i)
	{
		if (arr[idx].second < arr[i].second)
		{
			tmp = max(tmp, 1 + LIS(i));
		}
	}

	return dp[idx] = tmp;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);

	int lis = 0;
	for (int i = 0; i < n; ++i)
	{
		lis = max(lis, LIS(i));
	}

	cout << (n - lis) << endl;
}
