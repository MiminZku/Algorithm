#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> navers[1001];
priority_queue<pair<int, int>> pq;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		navers[a].push_back({ b, c });
		navers[b].push_back({ a, c });
	}

	vector<bool> visited(n + 1);
	pq.push({ 0, 1 });

	int ans = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur])
		{
			continue;
		}
		
		visited[cur] = true;
		ans += cost;

		for (const pair<int, int>& p : navers[cur])
		{
			if (visited[p.first])	continue;
			pq.push({ -p.second, p.first });
		}
	}

	cout << ans << endl;
}