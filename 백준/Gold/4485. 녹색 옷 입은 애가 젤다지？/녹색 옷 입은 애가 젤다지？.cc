#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int n;
int mat[150][150];
unsigned int dist[150][150];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void Dijkstra()
{
	priority_queue<pair<unsigned int, pair<int, int>>, vector<pair<unsigned int, pair<int, int>>>,
		greater<pair<unsigned int, pair<int, int>>>> q;
	dist[0][0] = mat[0][0];
	q.push({dist[0][0], {0, 0}});
	while (!q.empty())
	{
		int curY = q.top().second.first;
		int curX = q.top().second.second;
		int cost = q.top().first;
		q.pop();

		for (int i=0; i<4; ++i)
		{
			int nY = curY + dy[i];
			int nX = curX + dx[i];
			if (nY < 0 || nX < 0 || nY >= n || nX >= n)	continue;
			if (dist[nY][nX] > dist[curY][curX] + mat[nY][nX])
			{
				dist[nY][nX] = dist[curY][curX] + mat[nY][nX];
				q.push({ dist[nY][nX], {nY, nX} });
			}
		}
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	int t = 1;
	while (true)
	{
		memset(dist, -1, sizeof(dist));
		cin >> n;
		if (0 == n)	break;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> mat[i][j];
			}
		}

		Dijkstra();

		cout << "Problem " << t++ << ": " << dist[n - 1][n - 1] << endl;
	}

}