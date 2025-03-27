#include <iostream>
#include <memory.h>

using namespace std;

int m, n, k;
bool farm[50][50];
bool visited[50][50];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void DFS(int row, int col)
{
	visited[row][col] = true;
	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + row;
		int nx = dx[i] + col;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)	continue;
		if (farm[ny][nx] == false)	continue;
		if (visited[ny][nx])	continue;
		DFS(ny, nx);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		memset(farm, 0, sizeof(farm));
		memset(visited, 0, sizeof(visited));

		cin >> m >> n >> k;
		
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			farm[y][x] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (farm[i][j] == false)	continue;
				if (visited[i][j])	continue;
				DFS(i, j);
				++ans;
			}
		}

		cout << ans << '\n';
	}
}