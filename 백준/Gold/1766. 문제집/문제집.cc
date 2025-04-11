#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
int pre[32001];
vector<int> post[32001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		post[a].push_back(b);
		pre[b]++;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (pre[i] == 0)
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();

		cout << cur << ' ';

		for (int i : post[cur])
		{
			pre[i]--;
			if (pre[i] == 0)
			{
				pq.push(i);
			}
		}
	}
	cout << endl;
}