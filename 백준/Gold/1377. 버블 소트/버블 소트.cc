#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> arr[500'001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + 1 + n);

	int ans = -1'000'000;
	for (int i = 1; i <= n; ++i)
	{
		ans = max(ans, arr[i].second - i + 1);
	}
	cout << ans << endl;
}