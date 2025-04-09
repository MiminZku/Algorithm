#include <iostream>
#include <queue>
#include <set>

using namespace std;

int t;
int n, m;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		set<int> upper[501];
		set<int> lower[501];
		cin >> n;
		bool checked[501] = {};
		for (int i = 1, k; i <= n; ++i)
		{
			cin >> k;
			for (int j = 1; j <= n; ++j)
			{
				if (checked[j])
				{
					upper[k].insert(j);
				}
			}
			checked[k] = true;
			for (int j = 1; j <= n; ++j)
			{
				if (!checked[j])
				{
					lower[k].insert(j);
				}
			}
		}
		cin >> m;
		for (int i = 0, a, b; i < m; ++i)
		{
			cin >> a >> b;
			if (upper[a].find(b) != upper[a].end())
			{
				upper[a].erase(b);
				lower[a].insert(b);

				lower[b].erase(a);
				upper[b].insert(a);
			}
			else
			{
				upper[b].erase(a);
				lower[b].insert(a);

				lower[a].erase(b);
				upper[a].insert(b);
			}
		}

		queue<int> q;
		vector<int> ans;
		for (int i = 1; i <= n; ++i)
		{
			if (upper[i].size() == 0)
			{
				q.push(i);
			}
		}

		while (!q.empty())
		{
			if (q.size() > 1)
			{
				break;
			}
			int cur = q.front();
			q.pop();

			ans.push_back(cur);

			for (auto iter = lower[cur].begin(); iter != lower[cur].end(); ++iter)
			{
				upper[*iter].erase(cur);
				if (upper[*iter].size() == 0)
				{
					q.push(*iter);
				}
			}
		}

		if (ans.size() != n)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for (int i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}