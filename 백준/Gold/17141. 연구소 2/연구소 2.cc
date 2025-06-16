#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int mat[50][50];
vector<pair<int, int>> vCan;
int path[10];
int ans = 1'000'000'000;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

bool possible = false;

void Recur(int level, int start)
{
	if (level == m)
	{
		// Init
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] < 0)	continue;
				mat[i][j] = 0;
			}
		}

		// BFS
		queue<pair<int, int>> q;
		for (int i = 0; i < m; ++i)
		{
			int r = vCan[path[i]].first;
			int c = vCan[path[i]].second;
			q.push({ r, c});
			mat[r][c] = 1;
		}
		
		
		int time = 0;
		while (!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			time = mat[r][c];

			for (int i = 0; i < 4; ++i)
			{
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n)	continue;
				if (mat[nr][nc] != 0)	continue;
				mat[nr][nc] = mat[r][c] + 1;
				q.push({ nr, nc });
			}
		}
				
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] == 0)
				{
					return;
				}
			}
		}

		possible = true;
		ans = min(ans, time - 1);
		return;
	}

	for (int i = start; i < vCan.size(); ++i)
	{
		path[level] = i;
		Recur(level + 1, i + 1);
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 1)
			{
				mat[i][j] = -1;
			}
			else if (mat[i][j] == 2)
			{
				vCan.push_back({ i, j });
			}
		}
	}

	Recur(0, 0);

	cout << (possible ? ans : -1) << endl;
}