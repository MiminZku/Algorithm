#include <iostream>

using namespace std;

int t, n;
long long memo[1'000'001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;
	for (int i = 4; i <= 1'000'000; ++i)
	{
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
		memo[i] %= 1'000'000'009;
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << memo[n] << '\n';
	}
}