#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[10000];
int memo[10000][3];

int Recur(int level, int con)
{
	if (level == n)
	{
		return 0;
	}

	if (memo[level][con] != -1)
	{
		return memo[level][con];
	}

	int ret = 0;
	if (con < 2)
	{
		ret = max(ret, Recur(level + 1, con + 1) + arr[level]);
	}
	ret = max(ret, Recur(level + 1, 0));

	return memo[level][con] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << Recur(0, 0) << endl;
}