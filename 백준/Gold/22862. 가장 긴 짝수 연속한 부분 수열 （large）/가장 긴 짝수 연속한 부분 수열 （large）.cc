#include <iostream>

using namespace std;

int n, k;
int arr[100'0000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)	cin >> arr[i];

	int cnt = arr[0] % 2;
	int ans = (arr[0] % 2) ? 0 : 1;
	int s = 0, e = 0;
	while (s <= e && e < n)
	{
		if (cnt <= k)
		{
			ans = max(ans, e - s + 1 - cnt);
			++e;
			if (arr[e] % 2) ++cnt;
		}
		else
		{
			if (arr[s] % 2)	--cnt;
			++s;
		}
	}
	cout << ans << endl;
}