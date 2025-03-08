#include <iostream>

using namespace std;

string num;
long long cnt[10][82];	// cnt[i][j] : i로 시작하고 j자리인 증가하는 수의 개수

bool IsIncreasing(const string& n)
{
	char prev = n[0];
	for (int i = 1; i < n.length(); ++i)
	{
		if (prev > n[i])
		{
			return false;
		}
		prev = n[i];
	}
	return true;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	for (int i = 0; i < 10; ++i)
	{
		cnt[i][1] = 1;
	}
	for (int j = 2; j <= 81; ++j)    // 81까지 해야 80자리 전체 개수 계산 가능
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int k = i; k < 10; ++k)
			{
				cnt[i][j] += cnt[k][j - 1];
			}
		}
	}

	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		cin >> num;

		if (false == IsIncreasing(num))
		{
			cout << "-1\n";
			continue;
		}

		int len = num.length();
		long long ans = cnt[0][len + 1];
		for (int startIdx = 0; startIdx < len; ++startIdx)
		{
			int n = num[startIdx] - '0';
			for (int i = n + 1; i < 10; ++i)
			{
				ans -= cnt[i][len - startIdx];
			}
		}
		cout << ans - 1 << '\n';
	}
}