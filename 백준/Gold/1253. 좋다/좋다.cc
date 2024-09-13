#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2000];
int ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
	{
		bool check = false;
		int target = arr[i];
		int s = 0, e = n - 1;
		while (s < e)
		{
			if (s == i)
			{
				++s; continue;
			}
			if (e == i)
			{
				--e; continue;
			}

			int sum = arr[s] + arr[e];
			if (sum > target)
			{
				--e;
			}
			else if (sum < target)
			{
				++s;
			}
			else
			{
				check = true;
				break;
			}
		}
		if (check) ++ans;
	}
	cout << ans << endl;
}