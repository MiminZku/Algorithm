#include <iostream>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
map<int, int> road[10001];
int s, e;
long long dp[10001];	// dp[i] : i번 도시에서 도착 도시까지 걸리는 최대 시간
long long dp2[10001];	// dp2[i] : 시작도시에서 i번 도시까지 걸리는 최대 시간
int cnt;

long long Recur(int city)
{
	if (city == e)	return dp[city] = 0;

	if (dp[city] != -1)	return dp[city];

	long long temp = 0;
	for (auto iter = road[city].begin(); iter != road[city].end(); ++iter)
	{
		temp = max(temp, Recur(iter->first) + iter->second);
	}

	return dp[city] = temp;
}

long long Recur2(int city)
{
	if (city == s)	return dp2[city] = 0;

	if (dp2[city] != -1)	return dp2[city];

	long long temp = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (road[i].find(city) != road[i].end())
		{
			temp = max(temp, Recur2(i) + road[i][city]);
		}
	}

	return dp2[city] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	cin >> n >> m;
	int src, des, val;
	for (int i = 1; i <= m; ++i)
	{
		cin >> src >> des >> val;
		road[src].insert({ des, val });
	}
	cin >> s >> e;
	
	Recur(s);
	Recur2(e);

	cout << dp[s] << endl;

	for (int i = 1; i <= n; ++i)
	{	
		for (auto iter = road[i].begin(); iter != road[i].end(); ++iter)
		{
			if (dp2[i] + iter->second + dp[iter->first] == dp[s])	
				++cnt;
		}
	}

	cout << cnt << endl;
}
