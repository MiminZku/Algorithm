#include <iostream>

using namespace std;

int n, m;
int mat[500][500];
bool visited[500][500];
int ans;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

bool IsValid(int r, int c)
{
	return (r >= 0 && r < n && c >= 0 && c < m);
}

void Recur(int r, int c, int level, int total)
{
	if (level == 4)
	{
		ans = max(ans, total);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (false == IsValid(nr, nc))	continue;
		if (visited[nr][nc]) continue;
		visited[nr][nc] = true;
		if (level == 2)
		{
			Recur(r, c, level + 1, total + mat[nr][nc]);
		}
		Recur(nr, nc, level + 1, total + mat[nr][nc]);
		visited[nr][nc] = false;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			visited[i][j] = true;
			Recur(i, j, 1, mat[i][j]);
			visited[i][j] = false;
		}
	}

	cout << ans << endl;
}