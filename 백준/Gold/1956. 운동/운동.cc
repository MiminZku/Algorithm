#include <iostream>

using namespace std;

#define INF 1'000'000'000

int v, e;
int dist[401][401];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> v >> e;
	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			dist[i][j] = INF;
		}
	}
	for (int i = 0, a, b, c; i < e; ++i)
	{
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= v; ++k)
	{
		for (int i = 1; i <= v; ++i)
		{
			for (int j = 1; j <= v; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= v; ++i)
	{
		ans = min(ans, dist[i][i]);
	}
    
	if (ans == INF)
	{
		cout << "-1\n";
		return 0;
	}
	cout << ans << endl;
}