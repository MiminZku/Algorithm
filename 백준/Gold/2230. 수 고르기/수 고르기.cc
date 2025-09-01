#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100'000];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int l = 0, r = 0;
	int ans = 2'000'000'000;
	while (r < n)
	{
		int a = arr[l];
		int b = arr[r];
		int diff = b - a;

		if (diff == m)
		{
			ans = m;
			break;
		}
		if (diff > m)
		{
			ans = min(ans, diff);
			l++;
		}
		else
		{
			r++;
		}
	}

	cout << ans << endl;
}