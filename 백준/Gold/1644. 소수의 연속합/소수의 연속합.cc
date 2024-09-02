#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> isPrime;
vector<int> primeNums;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	isPrime.resize(n + 1, true);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= n; ++i)
	{
		if (false == isPrime[i])	continue;
		for (int j = i * i; j <= n; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if (isPrime[i])
		{
			primeNums.emplace_back(i);
		}
	}

	int ans = 0;
	int sum = primeNums.size() ? primeNums[0] : 0;
	int s = 0, e = 0;
	while (s <= e)
	{
		if (sum <= n)
		{
			if (sum == n)
			{
				++ans;
			}
			++e;
			if (e >= primeNums.size())	break;
			sum += primeNums[e];
		}
		else
		{
			sum -= primeNums[s];
			++s;
		}
	}
	cout << ans << endl;
}