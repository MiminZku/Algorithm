#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int n;
pair<int, int> ratio[10][10];
ll ans[10];

ll GCD(ll a, ll b)
{
	if (0 == b)	return a;
	return GCD(b, a % b);
}

ll LCM(ll a, ll b) 
{
	return a / GCD(a, b) * b;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	
	cin >> n;

	ll a, b, p, q;
	ll lcm = 1;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b >> p >> q;

		lcm *= LCM(p, q);

		ratio[a][b] = { p, q };
		ratio[b][a] = { q, p };
	}

	ans[0] = lcm;
	queue<int> que;
	que.push(0);
	while (!que.empty())
	{
		int cur = que.front(); que.pop();
		for (int i = 0; i < n; ++i)
		{
			if (0 == ratio[cur][i].first) continue;
			if (ans[i])	continue;
			ans[i] = ans[cur] * ratio[cur][i].second / ratio[cur][i].first;
			que.push(i);
		}
	}

	ll gcd = ans[0];
	for (int i = 1; i < n; ++i)
	{
		gcd = GCD(gcd, ans[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] / gcd << ' ';
	}
	cout << endl;
}