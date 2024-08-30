#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
vector<int> a, b;
vector<int> preSum;
unordered_map<int, int> cntMap;
long long ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n + 1, 0);
	b.resize(n + 1, 0);
	preSum.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	for (int i = 1; i <= n; ++i)	cin >> b[i];
	for (int i = 1; i <= n; ++i)
	{
		preSum[i] = preSum[i - 1] + (a[i] - b[i]);

		if (preSum[i] == 0)
			++ans;
		ans += cntMap[preSum[i]/* - 0 */];
		++cntMap[preSum[i]];
	}
	cout << ans << endl;
}