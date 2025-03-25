#include <iostream>

using namespace std;

int n;
int road[100000];
int oilCost[100000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> road[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> oilCost[i];
	}

	long long ans = 0;
	for (int i = 0, cost = 1000000000; i < n - 1; ++i)
	{
		cost = min(cost, oilCost[i]);
		ans += (long long)road[i] * cost;
	}
	cout << ans << endl;
}