#include <iostream>

using namespace std;

#define INF 1000000000

int n, m;
int dist[101][101];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)	continue;
			dist[i][j] = INF;
		}
	}
	for (int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] == INF)
			{
				cout << 0 << ' ';
				continue;
			}
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}