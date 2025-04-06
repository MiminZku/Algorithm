#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[100000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);

	int ans = 1;
	int lastStartTime = arr[n - 1].first;
	for (int i = n - 2; i >= 0; --i)
	{
		if (arr[i].second <= lastStartTime)
		{
			ans++;
			lastStartTime = arr[i].first;
		}
	}

	cout << ans << endl;
}