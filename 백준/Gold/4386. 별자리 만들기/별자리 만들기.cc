#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int n;
pair<float, float> stars[100];
priority_queue<pair<float, pair<int, int>>> edges;

int parent[100];

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
	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
		cin >> stars[i].first >> stars[i].second;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			float xDiff = stars[i].first - stars[j].first;
			float yDiff = stars[i].second - stars[j].second;
			edges.push({ -sqrt(xDiff * xDiff + yDiff * yDiff) , {i, j} });
		}
	}

	float ans = 0;
	int cnt = 0;
	while (cnt < n - 1)
	{
		float dist = -edges.top().first;
		int a = edges.top().second.first;
		int b = edges.top().second.second;
		edges.pop();

		if (Find(a) == Find(b))
		{
			continue;
		}
		Union(a, b);
		ans += dist;
		cnt++;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans << endl;
}