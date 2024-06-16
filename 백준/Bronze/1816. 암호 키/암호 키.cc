#include <iostream>
#include <vector>

using namespace std;

int n;
bool isPrime[1000001];
vector<int> primeNums;

bool Check(const long long& S)
{
	for (int i : primeNums)
	{
		if (S % i == 0)	return false;
	}
	return true;
}

int main()
{
	for (int i = 2; i <= 1000000; ++i)
	{
		isPrime[i] = true;
	}
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!isPrime[i])	continue;
		for (int j = i + i; j <= 1000000; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= 1000000; ++i)
	{
		if (isPrime[i])
		{
			primeNums.push_back(i);
		}
	}

	cin >> n;
	long long S;
	for (int i = 0; i < n; ++i)
	{
		cin >> S;
		if (Check(S))	cout << "YES\n";
		else			cout << "NO\n";
	}
}