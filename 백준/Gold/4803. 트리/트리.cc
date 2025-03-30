#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool dfs(int node, int prev, const vector<vector<int>>& navers, vector<bool>& visited)
{
	visited[node] = true;
	bool hasCycle = false;
	for (int naver : navers[node])
	{
		if (naver == prev)	continue;
		if (visited[naver])
		{
			hasCycle = true;
			continue;
		}
		hasCycle |= dfs(naver, node, navers, visited);
	}

	return hasCycle;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	int t = 1;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		vector<vector<int>> navers(n + 1);
		vector<bool> visited(n + 1, 0);

		for (int i = 0, a, b; i < m; ++i)
		{
			cin >> a >> b;
			navers[a].push_back(b);
			navers[b].push_back(a);
		}

		int treeCnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i])	continue;
			if (dfs(i, 0, navers, visited))	continue;
			treeCnt++;
		}

		cout << "Case " << t++ << ": ";
		if (treeCnt == 0)
		{
			cout << "No trees.";
		}
		else if (treeCnt == 1)
		{
			cout << "There is one tree.";
		}
		else
		{
			cout << "A forest of " << treeCnt << " trees.";
		}
		cout << '\n';
	}
}