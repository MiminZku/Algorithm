#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<bool> used(100'001, false);
	long long ans = 0;
	int l = 0, r = 0;
	for (int l = 0, r = 0; l < n; ++l)
	{
		while (r < n)
		{
			if (used[arr[r]])	break;
			used[arr[r]] = true;
			++r;
		}
		ans += (r - l);
		used[arr[l]] = false;
	}

	cout << ans << endl;
}