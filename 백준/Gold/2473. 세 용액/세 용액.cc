#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll arr[5000];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	ll minDiff = 3'000'000'000;
	int ans[3] = {};
	for (int a = 0; a < n - 2; ++a)
	{
		int b = a + 1;
		int c = n - 1;
		while (b < c)
		{
			ll value = arr[a] + arr[b] + arr[c];
			if (value == 0)
			{
				cout << arr[a] << ' ' << arr[b] << ' ' << arr[c] << endl;
				exit(0);
			}

			if (abs(value) < minDiff)
			{
				minDiff = abs(value);
				ans[0] = arr[a];
				ans[1] = arr[b];
				ans[2] = arr[c];
			}

			if (value < 0)
			{
				b++;
			}
			else
			{
				c--;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}