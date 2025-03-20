#include <iostream>

using namespace std;

int n;
int memo[1000001];

int main()
{
	cin >> n;

	memo[1] = 1;
	memo[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		memo[i] = memo[i - 2] + memo[i - 1];
		memo[i] %= 15746;
	}

	cout << memo[n] << endl;
}