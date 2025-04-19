#include <iostream>
#include <vector>
using namespace std;

#define INF 10'0000'0000

int n, m, w;
int dist[501];
vector<pair<pair<int, int>, int>> edges;

bool BellmanFord()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 2 * m + w; ++j)
		{
			int u = edges[j].first.first;
			int v = edges[j].first.second;
			int d = edges[j].second;

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
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> w;
		for (int i = 2; i <= n; ++i)
		{
			dist[i] = INF;
		}
		edges.clear();
		for (int i = 0, a, b, c; i < m; ++i)
		{
			cin >> a >> b >> c;
			edges.push_back({ { a, b }, c });
			edges.push_back({ { b, a }, c });
		}
		for (int i = 0, a, b, c; i < w; ++i)
		{
			cin >> a >> b >> c;
			edges.push_back({ { a, b }, -c });
		}
		
		if (BellmanFord())
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}