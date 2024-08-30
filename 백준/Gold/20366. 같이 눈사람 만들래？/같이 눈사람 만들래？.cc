#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[600];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	int ans = 2147483647;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int snowMan1 = arr[i] + arr[j];

			int s = 0, e = n - 1;
			while (s < e)
			{
				if (s == i || s == j)
				{
					s += 1;
					continue;
				}
				if (e == i || e == j)
				{
					e -= 1;
					continue;
				}

				int snowMan2 = arr[s] + arr[e];
				int diff = abs(snowMan2 - snowMan1);
				ans = min(ans, diff);
				if (snowMan2 < snowMan1)
				{
					s += 1;
				}
				else if (snowMan2 > snowMan1)
				{
					e -= 1;
				}
				else
				{
					cout << 0 << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;
}