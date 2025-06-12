#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, k, w;
int timeTaken[1001];
vector<int> prevBuildings[1001];
int memo[1001];

int Recur(int cur)
{
	if (memo[cur] != -1)
	{
		return memo[cur];
	}

	int ret = 0;
	for (int i : prevBuildings[cur])
	{
		ret = max(ret, Recur(i));
	}

	return memo[cur] = ret + timeTaken[cur];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		memset(memo, -1, sizeof(memo));
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			cin >> timeTaken[i];
			prevBuildings[i].clear();
		}
		for (int i = 0, a, b; i < k; ++i)
		{
			cin >> a >> b;
			prevBuildings[b].push_back(a);
		}
		cin >> w;

		cout << Recur(w) << '\n';		
	}
}