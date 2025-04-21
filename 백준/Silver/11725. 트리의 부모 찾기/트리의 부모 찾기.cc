#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> childs[100001];
int parent[100001];

void DFS(int cur, int prev)
{
	parent[cur] = prev;
	for (int child : childs[cur])
	{
		if (child == prev)	continue;
		DFS(child, cur);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1, a, b; i < n; ++i)
	{
		cin >> a >> b;
		childs[a].push_back(b);
		childs[b].push_back(a);
	}

	DFS(1, 0);

	for (int i = 2; i <= n; ++i)
	{
		cout << parent[i] << '\n';
	}
}