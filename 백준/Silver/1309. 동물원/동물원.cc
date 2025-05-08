#include <iostream>
#include <memory.h>

using namespace std;

#define MOD 9901

int n;

int memo[100'001][3];

int Recur(int row, int prev)	// prev : 0 이면 배치 안한경우, 1 이면 왼쪽, 2 면 오른쪽
{
	if (row == n)
	{
		return 1;
	}

	if (memo[row][prev] != -1)
	{
		return memo[row][prev];
	}

	int ret = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (prev != 0 && prev == i)	continue;
		ret += Recur(row + 1, i);
		ret %= MOD;
	}

	return memo[row][prev] = ret;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	cin >> n;

	cout << Recur(0, 0) << endl;
}