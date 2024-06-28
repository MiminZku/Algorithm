#include <iostream>

using namespace std;

int R, C;
char mat[10000][500];
bool visited[10000][500];
int dr[] = { -1, 0, 1 };

int res = 0;

bool DFS(int r, int c, int& cnt)
{
	if (r == R)	return false;

	visited[r][c] = true;
	if (c == C - 1)
	{
		++cnt;
		return true;
	}

	bool check = false;
	for (int i = 0; i < 3; ++i)
	{
		int nr = r + dr[i];
		int nc = c + 1;
		if (nr >= R || nc >= C || nr < 0 || nc < 0)	continue;
		if (mat[nr][nc] == 'x')	continue;
		if (visited[nr][nc])	continue;
		if (DFS(nr, nc, cnt))
		{
			check = true;
			break;
		}
	}

	if (c == 0)
	{
		return DFS(r + 1, c, cnt);
	}
	return check;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> mat[i][j];
		}
	}

	DFS(0, 0, res);

	cout << res << endl;
}