#include <iostream>

using namespace std;

int n, m;
int path[10];

void Recur(int level, int prev)
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

	for (int i = prev; i <= n; ++i)
	{
		path[level] = i;
		Recur(level + 1, i + 1);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;

	Recur(0, 1);
}