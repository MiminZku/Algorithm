#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll memo[31];

int main()
{
	cin >> n;

	memo[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		memo[i] = memo[i - 2] * 3;
		for (int j = 4; j <= i; j += 2)
		{
			memo[i] += memo[i - j] * 2;
		}
	}

	cout << memo[n] << endl;
}