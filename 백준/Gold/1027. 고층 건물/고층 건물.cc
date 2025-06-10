#include <iostream>

using namespace std;

#define ll long long

int n;
ll arr[50];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (ll j = 0; j < n; ++j)
		{
			if (i == j) continue;

			bool canSee = true;

			double a = (double)(arr[i] - arr[j]) / abs(i - j);
			for (ll k = j + 1; k < i; ++k)
			{
				if (arr[k] >= a * (k - i) + arr[i])
				{
					canSee = false;
					break;
				}
			}

			a = (double)(arr[j] - arr[i]) / abs(i - j);
			for (ll k = i + 1; k < j; ++k)
			{
				if (arr[k] >= a * (k - i) + arr[i])
				{
					canSee = false;
					break;
				}
			}

			if (canSee)
			{
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << endl;
}