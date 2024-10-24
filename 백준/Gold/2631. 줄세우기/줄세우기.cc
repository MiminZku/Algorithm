#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[200];
int dp[200];

int LIS(int idx)	// idx 인덱스부터 끝까지의 LIS
{
	if (dp[idx] != -1) return dp[idx];

	int tmp = 1;
	for (int i = idx + 1; i < n; ++i)
	{
		if (arr[i] > arr[idx])
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
		cin >> arr[i];
	}

	int lis = 0;
	for (int i = 0; i < n; ++i)
	{
		lis = max(lis, LIS(i));
	}

	cout << (n - lis) << endl;
}