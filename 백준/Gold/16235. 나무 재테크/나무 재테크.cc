#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m, k;
map<pair<int, int> , vector<int>> trees;
int soil[11][11];
int A[11][11];

void SS()
{
	for (auto& pos : trees)
	{
		int x = pos.first.first;
		int y = pos.first.second;

		vector<int> tmp;
		vector<int>& arr = pos.second;
		sort(arr.begin(), arr.end());
		int nut = 0;
		for (int z : arr)
		{
			if (soil[x][y] >= z)
			{
				soil[x][y] -= z;
				tmp.push_back(z + 1);
			}
			else
			{
				nut += z / 2;
			}
		}
		arr = tmp;
		soil[x][y] += nut;
	}
}

int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void FW()
{
	vector<pair<int, int>> tmp;
	for (auto& pos : trees)
	{
		int x = pos.first.first;
		int y = pos.first.second;

		vector<int>& arr = pos.second;
		for (int z : arr)
		{
			if (z % 5 != 0)	continue;

			for (int i = 0; i < 8; ++i)
			{
				int nr = x + dr[i];
				int nc = y + dc[i];

				if (nr < 1 || nc < 1 || nr > n || nc > n)	continue;

				tmp.push_back({ nr, nc });
			}
		}
	}
	for (auto& pos : tmp)
	{
		trees[pos].push_back(1);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			soil[i][j] += A[i][j];
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			soil[i][j] = 5;
			cin >> A[i][j];
		}
	}
	for (int i = 0, x, y, z; i < m; ++i)
	{
		cin >> x >> y >> z;
		trees[{x, y}].push_back(z);
	}

	for (int i = 0; i < k; ++i)
	{
		SS();
		FW();
	}

	int ans = 0;
	for (auto& p : trees)
	{
		ans += p.second.size();
	}
	cout << ans << endl;
}