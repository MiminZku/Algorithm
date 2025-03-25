#include <iostream>

using namespace std;

int n;
int road[100000];
int oilCost[100000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> road[i - 1];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> oilCost[i];
	}

	int curCity = 0;
	int curCost = oilCost[0];
	long long ans = 0;
	while (true)
	{
		ans += road[curCity] * curCost;
		++curCity;
		if (curCity == n)
		{
			break;
		}
		curCost = min(curCost, oilCost[curCity]);
	}
	cout << ans << endl;
}