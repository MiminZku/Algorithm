#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int v, e;
vector<int> navers[20001];
bool visited[20001];
int color[20001];
bool check = true;

void DFS(int cur)
{
	visited[cur] = true;
	for (int naver : navers[cur])
	{
		if (visited[naver])
		{
			if (color[cur] == color[naver])
			{
				check = false;
				return;
			}
			continue;
		}
		color[naver] = color[cur] * -1;
		DFS(naver);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	int k;
	cin >> k;
	while (k--)
	{
		cin >> v >> e;
		
		for (int i = 1; i <= v; ++i)
		{
			navers[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(color, 0, sizeof(color));
		check = true;


		for (int i = 0, u, v; i < e; ++i)
		{
			cin >> u >> v;
			navers[u].push_back(v);
			navers[v].push_back(u);
		}

		for (int i = 1; i <= v; ++i)
		{
			if (visited[i]) continue;
			color[i] = 1;
			DFS(i);
		}

		if (check)	cout << "YES\n";
		else		cout << "NO\n";
	}

}