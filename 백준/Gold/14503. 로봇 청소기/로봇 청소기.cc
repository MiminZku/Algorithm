#include <iostream>

using namespace std;

/*
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
*/

int n, m;
int mat[50][50];

int dr[] = {-1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1};

int ans = 0;

void Clean(int r, int c, int d)
{
	if (mat[r][c] == 0)
	{
		mat[r][c] = 1;
		ans++;
	}

	bool allCleaned = true;
	for (int i = 0; i < 4; ++i)
	{
		int nr = dr[i] + r;
		int nc = dc[i] + c;
		if (nr < 0 || nc < 0 || nr >= n || nc >= m)	continue;
		if (mat[nr][nc] < 0)	continue;
		if (mat[nr][nc] == 0)
		{
			allCleaned = false;
			break;
		}
	}

	if (allCleaned)
	{
		int nd = (d + 2) % 4;
		int nr = r + dr[nd];
		int nc = c + dc[nd];
		if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
			mat[nr][nc] >= 0)
		{
			Clean(nr, nc, d);
		}
		else
		{
			return;
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			d--;
			if (d < 0)
			{
				d += 4;
			}

			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
				mat[nr][nc] == 0)
			{
				Clean(nr, nc, d);
				break;
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
			mat[i][j] *= -1;
		}
	}

	Clean(r, c, d);

	cout << ans << endl;
}