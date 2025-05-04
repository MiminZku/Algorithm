#include <iostream>
#include <queue>

using namespace std;

#define P first
#define D second

int n;
priority_queue<pair<int, int>> pq;
bool visited[10001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0, p, d; i < n; ++i)
	{
		cin >> p >> d;
		pq.push({ p, d });
	}

	int ans = 0;
	visited[0] = true;
	while (!pq.empty())
	{
		auto pd = pq.top();
		pq.pop();
		while (pd.D > 1 && visited[pd.D])
		{
			pd.D--;
		}
		if (visited[pd.D] == false)
		{
			ans += pd.P;
			visited[pd.D] = true;
		}
	}

	cout << ans << endl;
}