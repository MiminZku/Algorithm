#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int> smallers[501];
vector<int> biggers[501];
int smallerCnt[501];
int biggerCnt[501];

int CntSmaller(int cur, bool visited[])
{
	visited[cur] = true;
	int ret = 1;
	for (int i : smallers[cur])
	{
		if (visited[i]) continue;
		ret += CntSmaller(i, visited);
	}
	return ret;
}

int CntBigger(int cur, bool visited[])
{
	visited[cur] = true;
	int ret = 1;
	for (int i : biggers[cur])
	{
		if (visited[i]) continue;
		ret += CntBigger(i, visited);
	}
	return ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		biggers[a].push_back(b);
		smallers[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		bool visited[501] = {};
		smallerCnt[i] = CntSmaller(i, visited) - 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		bool visited[501] = {};
		biggerCnt[i] = CntBigger(i, visited) - 1;

		if (smallerCnt[i] + biggerCnt[i] == n - 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
}