#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int l = 0, r = n - 1;
	int ans[2] = { -1, -1 };
	int minDiff = 2147483647;
	while (l < r)
	{
		int sum = arr[l] + arr[r];
		if (abs(sum) < minDiff)
		{
			minDiff = abs(sum);
			ans[0] = arr[l];
			ans[1] = arr[r];
		}
		else
		{
			if (sum > 0)
			{
				--r;
			}
			else
			{
				++l;
			}
		}
	}
	cout << ans[0] << ' ' << ans[1] << endl;
}