#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;

int n, m, t;
int s, g, h;
int desCan[100];
int ghLen;
vector<pair<int,int>> roadsFrom[2001];
unsigned int minDistFromSTo[2001];
unsigned int minDistFromGTo[2001];
unsigned int minDistFromHTo[2001];

void Dijkstra(int src, unsigned int* minDist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, src });
	minDist[src] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (const auto& road: roadsFrom[cur])
		{
			int des = road.first;
			int len = road.second;
			if (dist + len < minDist[des])
			{
				minDist[des] = dist + len;
				pq.push({ dist + len, des });
			}
		}
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> t >> s >> g >> h;
		memset(desCan, 0, sizeof(desCan));
		memset(minDistFromSTo, -1, sizeof(minDistFromSTo));
		memset(minDistFromGTo, -1, sizeof(minDistFromGTo));
		memset(minDistFromHTo, -1, sizeof(minDistFromHTo));
		for (int i = 1; i <= n; ++i)
		{
			roadsFrom[i].clear();
		}

		for (int i = 0, a, b, d; i < m; ++i)
		{
			cin >> a >> b >> d;
			if (a == g && b == h || a == h && b == g)
			{
				ghLen = d;
			}
			roadsFrom[a].push_back({ b, d });
			roadsFrom[b].push_back({ a, d });
		}
		for (int i = 0; i < t; ++i)
		{
			cin >> desCan[i];
		}

		Dijkstra(s, minDistFromSTo);
		Dijkstra(g, minDistFromGTo);
		Dijkstra(h, minDistFromHTo);

		sort(desCan, desCan + t);

		for (int i = 0; i < t; ++i)
		{
			int des = desCan[i];
			int distToDes = minDistFromSTo[des];
			int distGH = minDistFromSTo[g] + ghLen + minDistFromHTo[des];
			int distHG = minDistFromSTo[h] + ghLen + minDistFromGTo[des];
			if (distToDes == distGH || distToDes == distHG)
			{
				cout << des << ' ';
			}
		}
		cout << '\n';
	}
}