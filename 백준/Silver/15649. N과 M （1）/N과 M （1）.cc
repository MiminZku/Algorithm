#include <iostream>

using namespace std;

int n, m;
int path[10];
bool visited[10];

void Recur(int level)
{
	if (level == m)
	{
		for (int i = 0; i < level; ++i)
		{
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (visited[i])	continue;
		visited[i] = true;
		path[level] = i;
		Recur(level + 1);
		visited[i] = false;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;

	Recur(0);
}