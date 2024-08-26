#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, k;
vector<int> preSum;
unordered_map<int, int> cntMap;
long long ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	preSum.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int j;
		cin >> j;
		preSum[i] = j + preSum[i - 1];

		if (preSum[i] == k)
			++ans;
		if (cntMap[preSum[i] - k] > 0)
			ans += cntMap[preSum[i] - k];

		++cntMap[preSum[i]];
	}
	cout << ans << endl;
}