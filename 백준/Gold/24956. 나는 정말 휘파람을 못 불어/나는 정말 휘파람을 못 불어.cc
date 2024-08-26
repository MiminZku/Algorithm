#include <iostream>

using namespace std;

int n;
char str[200002];
int prefixW[200002];
int suffixE[200002];
int mod = 1'000'000'007;
int powArr[200001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> str[i];
		if ('W' == str[i])	prefixW[i] = 1;
		if ('E' == str[i])	suffixE[i] = 1;
	}
	for (int i = 1, j = n; i <= n; ++i, --j)
	{
		prefixW[i] += prefixW[i - 1];
		suffixE[j] += suffixE[j + 1];
	}

	unsigned long long temp = 1;
	for (int i = 1; i <= suffixE[1]; ++i)
	{
		temp *= 2;
		temp %= mod;
		powArr[i] = temp;
	}

	unsigned long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if ('H' != str[i])	continue;
		if (suffixE[i] < 2)	continue;
		unsigned long long temp = powArr[suffixE[i]] - (1 + suffixE[i]);
		
		// ??
		if (temp < 0)	temp = 0;
		
		res += prefixW[i] * temp;
		res %= mod;
	}
	cout << res << endl;
}