#include <iostream>

using namespace std;

int n, m;
int arr[100'001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	int maxLen = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		maxLen = max(maxLen, arr[i]);
	}

	int ans = 0;
	int s = maxLen, e = 1'000'000'000;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		int cnt = 1;
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (sum + arr[i] <= mid)
			{
				sum += arr[i];
			}
			else
			{
				cnt++;
				sum = arr[i];
			}
		}

		if (cnt > m)
		{
			s = mid + 1;
		}
		else
		{
			ans = mid;
			e = mid - 1;
		}
	}

	cout << ans << endl;
}