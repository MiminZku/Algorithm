#include <iostream>

using namespace std;

const int MOD = 1'000'000'000;
int n, k;
int memo[201][201];

int Recur(int cnt, int num)
{
	if (cnt == 0)
	{
		return 0;
	}
	if (cnt == 1)
	{
		return 1;
	}

	if (memo[cnt][num] != 0)
	{
		return memo[cnt][num];
	}

	int ret = 0;
	for (int i = num; i >= 0; --i)
	{
		ret += Recur(cnt - 1, i);
		ret %= MOD;
	}

	return memo[cnt][num] = ret;
}

int main()
{
	cin >> n >> k;

	cout << Recur(k, n) << endl;
}