#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<long long> sum(1'000'001, 1);

	for (long long  i = 2; i <= 1'000'000; ++i)
	{
		for (long long j = i; j <= 1'000'000; j += i)
		{
			sum[j] += i;
		}
	}

	for (int i = 2; i <= 1'000'000; ++i)
	{
		sum[i] += sum[i - 1];
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		cout << sum[n] << '\n';
	}
}