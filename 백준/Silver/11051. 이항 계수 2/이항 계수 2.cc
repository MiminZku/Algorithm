#include <iostream>

using namespace std;

const int M = 10007;

int n, k;
int memo[1001][1001];

int main()
{
	cin >> n >> k;

	memo[1][0] = memo[1][1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		memo[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
			memo[i][j] %= M;
		}
	}

	cout << memo[n][k] << endl;
}