#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int t, n, m;
int arrA[1001];
int arrB[1001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> t >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arrA[i];
		arrA[i] += arrA[i - 1];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> arrB[i];
		arrB[i] += arrB[i - 1];
	}

	vector<int> aSubs, bSubs;
	unordered_map<int, int> aSubCnt, bSubCnt;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			int k = arrA[j] - arrA[i - 1];
			aSubs.push_back(k);
			aSubCnt[k]++;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = i; j <= m; ++j)
		{
			int k = arrB[j] - arrB[i - 1];
			bSubs.push_back(k);
			bSubCnt[k]++;
		}
	}

	sort(aSubs.begin(), aSubs.end());
	aSubs.erase(unique(aSubs.begin(), aSubs.end()), aSubs.end());
	sort(bSubs.begin(), bSubs.end());
	bSubs.erase(unique(bSubs.begin(), bSubs.end()), bSubs.end());

	long long ans = 0;
	int a = 0, b = bSubs.size() - 1;
	while (a < aSubs.size() && b >= 0)
	{
		int sum = aSubs[a] + bSubs[b];
		if (sum < t)
		{
			a++;
		}
		else if (sum > t)
		{
			b--;
		}
		else
		{
			ans += (long long)aSubCnt[aSubs[a]] * bSubCnt[bSubs[b]];
			a++;
			b--;
		}
	}
	cout << ans << endl;
}