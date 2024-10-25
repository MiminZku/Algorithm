#include <iostream>
#include <memory.h>

using namespace std;

int t, w;
bool arr[1000];
int dp[1000][30][2];

int Recur(int idx, int cnt, bool tree)
{
	if (idx == t) return 0;

	if (-1 != dp[idx][cnt][tree]) return dp[idx][cnt][tree];

	int tmp = 0;
	if (arr[idx] == tree)
	{
		tmp = max(tmp, 1 + Recur(idx + 1, cnt, tree));
	}
	else
	{
		if (cnt < w)
		{
			tmp = max(tmp, 1 + Recur(idx + 1, cnt + 1, !tree));
		}
		tmp = max(tmp, Recur(idx + 1, cnt, tree));
	}

	return dp[idx][cnt][tree] = tmp;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> t >> w;
	for (int i = 0, k; i < t; ++i)
	{
		cin >> k;
		arr[i] = k - 1;
	}

	cout << Recur(0, 0, 0) << endl;
}