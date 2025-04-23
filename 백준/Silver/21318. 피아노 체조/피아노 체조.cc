#include <iostream>

using namespace std;

int n, q;
int scores[100002];
int mistakes[100002];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> scores[i];
	}
	scores[n + 1] = 1000000000;
	for (int i = 1; i <= n; ++i)
	{
		mistakes[i] = scores[i] > scores[i + 1];
		mistakes[i] += mistakes[i - 1];
	}

	cin >> q;
	for (int i = 0, x, y; i < q; ++i)
	{
		cin >> x >> y;
		
		if (x == y)
		{
			cout << "0\n";
			continue;
		}

		cout << mistakes[y - 1] - mistakes[x - 1] << '\n';
	}
}