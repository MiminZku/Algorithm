#include <iostream>

using namespace std;

int n;
int prefixSum[367];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0, a, b; i < n; ++i)
	{
		cin >> a >> b;
		prefixSum[a] += 1;
		prefixSum[b + 1] -= 1;
	}

	for (int i = 1; i <= 366; ++i)
	{
		prefixSum[i] += prefixSum[i - 1];
	}

	int ans = 0;
	int maxHeight = 0;
	int start = 0;
	for (int i = 1; i <= 366; ++i)
	{
		if (prefixSum[i] == 0 && start != 0)
		{
			ans += (i - start) * maxHeight;
			maxHeight = 0;
			start = 0;
		}
		if (start == 0 && prefixSum[i] != 0)
		{
			start = i;
		}
		maxHeight = max(maxHeight, prefixSum[i]);
	}

	cout << ans << endl;
}