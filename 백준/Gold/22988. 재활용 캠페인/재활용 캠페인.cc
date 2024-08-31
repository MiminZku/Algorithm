#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long x;
long long arr[100000];
int cnt;
int ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int s = 0, e = n - 1;
	while (s <= e)
	{
		if (arr[e] >= x)
		{
			++ans;
			--e;
			continue;
		}

		long long sum = arr[s] + arr[e];
		if (s < e && sum * 2 >= x)
		{
			++ans;
			++s;
			--e;
		}
		else
		{
			++s;
			++cnt;
		}
	}
	cout << ans + cnt / 3 << endl;
}