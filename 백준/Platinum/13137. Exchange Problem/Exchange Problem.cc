#include <iostream>

using namespace std;

int n;
int coinValue[100];

int memo[200000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> coinValue[i];
	}

	if (n == 1)
	{
		cout << "Yes\n";
		return 0;
	}

	for (int c = 1; c < coinValue[1]; ++c)
	{
		memo[c] = c;
	}
	for (int c = coinValue[1]; c < 2 * coinValue[n - 1]; ++c)
	{
		int tmp = 1000000;
		for (int i = 0; i < n; ++i)
		{
			if (coinValue[i] > c)	break;
			tmp = min(tmp, memo[c - coinValue[i]]);
		}
		memo[c] = 1 + tmp;
	}

	bool check = true;
	for (int c = 1; c < 2 * coinValue[n - 1]; ++c)
	{
		int cnt = 0;
		int remain = c;
		for (int i = n - 1; i >= 0; --i)
		{
			if (remain < coinValue[i])	continue;
			cnt += remain / coinValue[i];
			remain %= coinValue[i];
		}

		if (cnt != memo[c])
		{
			check = false;
			break;
		}
	}

	cout << (check ? "Yes\n" : "No\n");
}