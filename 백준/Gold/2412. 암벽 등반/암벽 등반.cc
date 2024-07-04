#include <iostream>
#include <queue>
#include <map>

using namespace std;

int n, T;
map<pair<int, int>, bool> crd;

int BFS(int x, int y)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x,y},0 });

	while (!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curDist = q.front().second;
		q.pop();

		if (curY == T)
		{
			return curDist;
		}

		for (int i = -2; i <= 2; ++i)
		{
			for (int j = -2; j <= 2; ++j)
			{
				if (0 == i && 0 == j) continue;
				int nX = curX + i;
				int nY = curY + j;
				if (nX < 0 || nY < 0 || nX > 1000000 || nY > T) continue;
				if (crd.find(make_pair(nX, nY)) == crd.end())	continue;
				if (crd[make_pair(nX, nY)])	continue;
				crd[make_pair(nX, nY)] = true;
				q.push({ {nX, nY}, curDist + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> T;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		crd.insert({ { x, y }, false });
	}

	cout << BFS(0, 0) << endl;
}