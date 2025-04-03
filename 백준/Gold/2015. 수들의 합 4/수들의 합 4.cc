#include <iostream>
#include <unordered_map>

using namespace std;

int n, k;
int preSum[200002];
unordered_map<int, int> sumCnt;
long long ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> preSum[i];
		preSum[i] += preSum[i - 1];

		if (preSum[i] == k)
		{
			++ans;
		}
		if (sumCnt.find(preSum[i] - k) != sumCnt.end())
		{
			ans += sumCnt[preSum[i] - k];
		}
		++sumCnt[preSum[i]];
	}
	cout << ans << endl;
}