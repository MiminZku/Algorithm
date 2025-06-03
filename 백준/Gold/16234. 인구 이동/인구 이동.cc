#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int n, L, R;
int mat[50][50];
bool visited[50][50];

int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };

int BFS(int r, int c)
{
	visited[r][c] = true;
	queue<pair<int, int>> q;
	q.push({ r, c });

	vector<pair<int, int>> arr;
	int sum = 0;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
	
		arr.push_back(p);
		sum += mat[p.first][p.second];

		for (int i = 0; i < 4; ++i)
		{
			int nr = p.first + dr[i];
			int nc = p.second + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n)	continue;
			int diff = abs(mat[p.first][p.second] - mat[nr][nc]);
			if (diff < L || R < diff)	continue;
			if (visited[nr][nc])	continue;
			visited[nr][nc] = true;
			q.push({ nr, nc });
		}
	}

	for (const auto& p : arr)
	{
		mat[p.first][p.second] = sum / arr.size();
	}
	return arr.size();
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> L >> R;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	while (true)
	{
		memset(visited, 0, sizeof(visited));
		bool moved = false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j])	continue;
				if (BFS(i, j) > 1)
				{
					moved = true;
				}
			}
		}

		if (moved)
		{
			ans++;
		}
		else
		{
			break;
		}
	}

	cout << ans << endl;
}