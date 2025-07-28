#include <iostream>

using namespace std;

int x, y;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> x >> y;

		int src = 0;
		int des = y - x;
		int cnt = 0;
		long long moved = 0;
		for (int i = 1, cnt = 0; ; ++i)
		{
			moved += (long long)i * 2;
			cnt += 2;

			if (moved - i >= des)
			{
				cout << (cnt - 1) << '\n';
				break;
			}
			else if (moved >= des)
			{
				cout << cnt << '\n';
				break;
			}
		}
	}
}