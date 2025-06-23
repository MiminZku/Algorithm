#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
vector<int> friends[2000];
bool visited[2000];

bool ans;

void DFS(int cur, int level)
{
	visited[cur] = true;

	if (level == 4)
	{
		ans |= true;
		return;
	}

	for (int frnd : friends[cur])
	{
		if (visited[frnd])	continue;
		DFS(frnd, level + 1);
	}

	visited[cur] = false;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		DFS(i, 0);
	}

	cout << ans << endl;
}