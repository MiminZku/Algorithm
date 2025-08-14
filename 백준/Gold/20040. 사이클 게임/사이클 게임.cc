#include <iostream>

using namespace std;

int n, m;
int parent[500'000];
bool visited[500'000];

int Find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int aParent = Find(a);
	int bParent = Find(b);
	if (aParent != bParent)
	{
		parent[aParent] = bParent;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}
	int ans = 0;
	bool check = false;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		if (!check && Find(a) == Find(b) && visited[a] && visited[b])
		{
			check = true;
			ans = i + 1;
		}
		visited[a] = visited[b] = true;
		Union(a, b);
	}

	cout << ans << endl;
}