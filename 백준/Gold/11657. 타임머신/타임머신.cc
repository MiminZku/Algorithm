#include <iostream>
#include <vector>
using namespace std;

#define INF 10'0000'0000

int n, m;
long long dist[501];
vector<pair<pair<int, int>, int>> edges;

bool BellmanFord()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int u = edges[j].first.first;
			int v = edges[j].first.second;
			int d = edges[j].second;

			if (dist[u] == INF)	continue;
			if (dist[u] + d < dist[v])
			{
				dist[v] = dist[u] + d;
				if (i == n)	// n번 째 반복에 갱신되면 Negative Cycle 존재
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
	for (int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		edges.push_back({ {a,b}, c });
	}

	if (!BellmanFord())
	{
		cout << "-1\n";
		return 0;
	}
	for (int i = 2; i <= n; ++i)
	{
		if (dist[i] == INF)
		{
			cout << "-1\n";
			continue;
		}
		cout << dist[i] << '\n';
	}
}