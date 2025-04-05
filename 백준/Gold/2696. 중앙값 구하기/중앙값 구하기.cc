#include <iostream>
#include <queue>

using namespace std;

int t;
int m;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		cin >> m;

		int center;
		priority_queue<int, vector<int>, greater<int>> bigger;
		priority_queue<int> smaller;
		vector<int> ans;
		cin >> center;
		ans.push_back(center);
		for (int i = 1, k; i < m; ++i)
		{
			cin >> k;
			if (k >= center)
			{
				bigger.push(k);
			}
			else
			{
				smaller.push(k);
			}
			if (i % 2 != 0)	continue;

			if (bigger.size() < smaller.size())
			{
				bigger.push(center);
				center = smaller.top();
				smaller.pop();
			}
			else if (bigger.size() > smaller.size())
			{
				smaller.push(center);
				center = bigger.top();
				bigger.pop();
			}
			ans.push_back(center);
		}
		cout << (m / 2) + (m % 2);
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i % 10 == 0)
			{
				cout << '\n';
			}
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
}