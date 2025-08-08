#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n, m;
set<int> prevSingers[1001];
set<int> nextSingers[1001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0, j, k, l; i < m; ++i)
	{
		cin >> k;
		int pre;
		cin >> pre;
		for (j = 1; j < k; ++j)
		{
			cin >> l;
			nextSingers[pre].insert(l);
			prevSingers[l].insert(pre);
			pre = l;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (prevSingers[i].empty())
		{
			q.push(i);
		}			
	}

	vector<int> ans;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		ans.push_back(cur);
		for (auto iter = nextSingers[cur].begin(); iter != nextSingers[cur].end(); ++iter)
		{
			prevSingers[*iter].erase(cur);
			if (prevSingers[*iter].empty())
			{
				q.push(*iter);
			}
		}
	}

	if (ans.size() != n)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i : ans)
	{
		cout << i << '\n';
	}
}