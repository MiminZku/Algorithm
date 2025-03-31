#include <iostream>

using namespace std;

int n;
int weight[30];
int m;

int maxWeight;
bool memo[15555];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i];
		maxWeight += weight[i];
	}

	memo[0] = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = maxWeight; j >= 0; --j)
		{
			if (memo[j] == false)	continue;
			memo[j + weight[i]] = true;
		}
		for (int j = 0; j <= maxWeight; ++j)
		{
			if (memo[j] == false)	continue;
			memo[abs(j - weight[i])] = true;
		}
	}

	cin >> m;
	for (int i = 0, k; i < m; ++i)
	{
		cin >> k;
		if (k <= maxWeight && memo[k])
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}
	cout << endl;
}