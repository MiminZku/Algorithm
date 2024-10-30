#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n;
vector<int> navers[3001];
int degree[3001];
bool visited[3001];

int BFS(int start)
{
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = true;
	
	int ret = -1;
	while (!q.empty())
	{
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (2 == degree[cur])
		{
			ret = dist;
			break;
		}

		for (int naver : navers[cur])
		{
			if (visited[naver])	continue;
			visited[naver] = true;
			q.push({ naver, dist + 1 });
		}
	}
	return ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		navers[a].push_back(b);
		navers[b].push_back(a);
		++degree[a];
		++degree[b];
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (1 != degree[i])	continue;
		--degree[i];
		q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int naver : navers[cur])
		{					
			--degree[naver];
			if (1 == degree[naver])
			{
				q.push(naver);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		memset(visited, 0, sizeof(visited));

		cout << BFS(i) << ' ';
	}
	cout << endl;
}