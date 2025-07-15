#include <iostream>
#include <vector>

using namespace std;

int r, c;
char mat[50][50];
bool visited[50][50];
vector<pair<int, int>> waterPos;
vector<pair<int, int>> srcPos;
pair<int, int> desPos;

int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> mat[i][j];
			if (mat[i][j] == '*')
			{
				waterPos.push_back({ i, j });
			}
			else if (mat[i][j] == 'S')
			{
				srcPos.push_back({i, j});
				visited[i][j] = true;
			}
			else if (mat[i][j] == 'D')
			{
				desPos = { i, j };
			}
		}
	}

	int ans = 0;
	while (true)
	{
		ans++;
		vector<pair<int, int>> newWaterPos;
		for (auto p : waterPos)
		{
			for (int i = 0; i < 4; ++i)
			{
				int nr = p.first + dr[i];
				int nc = p.second + dc[i];
				if (nr < 0 || nc < 0 || nr >= r || nc >= c)	continue;
				if (mat[nr][nc] == 'X')	continue;
				if (mat[nr][nc] == 'D')	continue;
				if (mat[nr][nc] == '*') continue;
				mat[nr][nc] = '*';
				newWaterPos.push_back({ nr, nc });
			}
		}
		waterPos = newWaterPos;

		vector<pair<int, int>> newSrcPos;
		for (auto p : srcPos)
		{
			for (int i = 0; i < 4; ++i)
			{
				int nr = p.first + dr[i];
				int nc = p.second + dc[i];
				if (nr < 0 || nc < 0 || nr >= r || nc >= c)	continue;
				if (mat[nr][nc] == 'X')	continue;
				if (mat[nr][nc] == '*')	continue;
				if (visited[nr][nc])	continue;
				visited[nr][nc] = true;
				newSrcPos.push_back({ nr, nc });
			}
		}
		srcPos = newSrcPos;

		if (srcPos.empty())
		{
			cout << "KAKTUS\n";
			break;
		}

		for (auto p : srcPos)
		{
			if (p == desPos)
			{
				cout << ans << endl;
				return 0;
			}
		}
	}
}