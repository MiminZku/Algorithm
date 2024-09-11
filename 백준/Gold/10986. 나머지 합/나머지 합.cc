#include <iostream>

using namespace std;

int n, m;
int preSum[1001010];
int preSumCnt[1001];
long long ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	preSumCnt[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		preSum[i] = (preSum[i - 1] + k) % m;

		ans += preSumCnt[preSum[i]]++;
	}

	cout << ans << endl;
}