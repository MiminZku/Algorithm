#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> navers[3001];
int degree[3001];
int dist[3001];

void BFS(int start)
{
	queue<pair<int, int>> q;
	q.push({start, 0});
	bool visited[3001] = {};
	visited[start] = true;
	
	while (!q.empty())
	{
		int cur = q.front().first;
		int d = q.front().second;
		q.pop();

		dist[cur] = d;

		for (int naver : navers[cur])
		{
			if (visited[naver])	continue;
			visited[naver] = true;

			if (2 == degree[naver])
			{
				q.push({ naver, 0 });
			}
			else
			{
				q.push({ naver, d + 1 });
			}
		}
	}
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
		if (2 == degree[i])
		{
			BFS(i);
			break;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << dist[i] << ' ';
	}
	cout << endl;
}