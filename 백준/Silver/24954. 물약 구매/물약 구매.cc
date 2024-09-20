#include <iostream>

using namespace std;

int n;
int cost[10];
int saleInfo[10][10];	// saleInfo[i][j] : i번 물약을 사면 j번 물약이 얼마나 할인되는지
int ans = 10000;
bool selected[10];

void Recur(int level, int total)
{
	if (level == n)
	{
		ans = min(ans, total);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (selected[i]) continue;
		selected[i] = true;

		int finalCost = cost[i];
		for (int j = 0; j < n; ++j)
		{
			if (!selected[j])	continue;
			finalCost -= saleInfo[j][i];
		}
		Recur(level + 1, total + max(1, finalCost));

		selected[i] = false;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			int a, b;
			cin >> a >> b;
			saleInfo[i][a - 1] = b;
		}
	}

	Recur(0, 0);

	cout << ans << endl;
}