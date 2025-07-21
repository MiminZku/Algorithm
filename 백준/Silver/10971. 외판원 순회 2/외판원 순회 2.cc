#include <iostream>

using namespace std;

int n;
int cost[10][10];
bool visited[10];
int ans = 1'000'000'000;

void DFS(int level, int cur, int total, const int start)
{
	visited[cur] = true;
	for (int next = 0; next < n; ++next)
	{
		if (cost[cur][next] == 0)	continue;
		if (visited[next])	continue;

		DFS(level + 1, next, total + cost[cur][next], start);
	}
	visited[cur] = false;

	if (level == n && cost[cur][start] != 0)
	{
		ans = min(ans, total + cost[cur][start]);
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> cost[i][j];
		}
	}

	DFS(1, 0, 0, 0);	

	cout << ans << endl;
}