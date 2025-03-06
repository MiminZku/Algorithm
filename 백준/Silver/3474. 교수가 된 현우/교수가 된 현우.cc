#include <iostream>

using namespace std;

int t, n;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> n;

		int cnt2 = 0;
		for (int i = 2; i <= n; i *= 2)
		{
			cnt2 += n / i;
		}

		int cnt5 = 0;
		for (int i = 5; i <= n; i *= 5)
		{
			cnt5 += n / i;
		}

		cout << min(cnt2, cnt5) << '\n';
	}
}