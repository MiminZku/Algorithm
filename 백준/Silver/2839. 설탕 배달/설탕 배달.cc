#include <iostream>
#include <memory.h>

using namespace std;

int n;

int memo[5555];

int Recur(int total)
{
	if(total < 0)
	{
		return 10000;
	}
	if(total == 0)
	{
		return 0;
	}

	if(memo[total] != -1)
	{
		return memo[total];
	}

	return memo[total] = 1 + min(Recur(total - 3), Recur(total - 5));
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	memset(memo, -1, sizeof(memo));

	int ans = Recur(n);

	if(ans >= 10000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << endl;
	}
}