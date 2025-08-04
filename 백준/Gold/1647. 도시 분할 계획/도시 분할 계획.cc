#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<pair<int,pair<int, int>>> edges;
int parent[100'001];
bool visited[100'001];

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


	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}
	cin >> m;
	for (int i = 0, a, b, c; i < m; ++i)
	{
		cin >> a >> b >> c;
		edges.push({ -c, {a, b} });
	}

	vector<int> costs;
	int i = 1;
	while (i < n)
	{
		int cost = -edges.top().first;
		int a = edges.top().second.first;
		int b = edges.top().second.second;
		edges.pop();

		int aParent = Find(a);
		int bParent = Find(b);
		if (aParent == bParent)	continue;
		Union(a, b);

		costs.push_back(cost);

		i++;
	}

	int ans = 0;
	for (int i = 0; i < costs.size() - 1; ++i)
	{
		ans += costs[i];
	}

	cout << ans << endl;
}