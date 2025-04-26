#include <iostream>

using namespace std;

int n;
int memo[1001];	// memo[i] : 카드 i 개 사기 위한 최대 금액

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> memo[i];
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			memo[i] = max(memo[i], memo[i - j] + memo[j]);
		}
	}

	cout << memo[n] << endl;
}