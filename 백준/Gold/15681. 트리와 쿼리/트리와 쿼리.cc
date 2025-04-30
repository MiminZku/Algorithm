#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> childs[100001];
int memo[100001];

int DFS(int cur, int prev)
{
	if (memo[cur] != 0)
	{
		return memo[cur];
	}

	int ret = 1;
	for (int child : childs[cur])
	{
		if (prev == child)	continue;
		ret += DFS(child, cur);
	}

	return memo[cur] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> r >> q;
	for (int i = 1, u, v; i < n; ++i)
	{
		cin >> u >> v;
		childs[u].push_back(v);
		childs[v].push_back(u);
	}

	DFS(r, 0);

	int u;
	while (q--)
	{
		cin >> u;
		cout << memo[u] << '\n';
	}
}