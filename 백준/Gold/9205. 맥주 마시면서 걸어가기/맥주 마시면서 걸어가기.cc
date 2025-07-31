#include <iostream>
#include <queue>

using namespace std;

int t, n;
pair<int, int> src;
pair<int, int> spot[101];

int Distance(const pair<int, int>& a, const pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool BFS()
{
	bool visited[101] = {};
	queue<pair<int, int>> q;
	q.push(src);

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (cur == spot[n])
		{
			return true;
		}

		for (int i = 0; i <= n; ++i)
		{
			if (visited[i])	continue;
			int dist = Distance(cur, spot[i]);
			if (dist > 1000) continue;
			visited[i] = true;
			q.push(spot[i]);
		}
	}

	return false;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> src.first >> src.second;
		for (int i = 0; i <= n; ++i)
		{
			cin >> spot[i].first >> spot[i].second;
		}

		if (BFS())
		{
			cout << "happy\n";
		}
		else
		{
			cout << "sad\n";
		}
	}
}