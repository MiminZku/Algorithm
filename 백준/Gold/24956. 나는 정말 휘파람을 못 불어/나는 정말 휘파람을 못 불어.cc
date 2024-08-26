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
		prefixW[i] = prefixW[i - 1] + ('W' == str[i]);
	}
	for (int j = n; j >= 1; --j)
	{
		suffixE[j] = suffixE[j + 1] + ('E' == str[j]);
	}

	unsigned long long temp = 1;
	for (int i = 1; i <= suffixE[1]; ++i)
	{
		temp = temp * 2 % mod;
		powArr[i] = temp;
	}

	unsigned long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if ('H' != str[i])	continue;
		if (suffixE[i] < 2)	break;
		
		unsigned long long temp = powArr[suffixE[i]] - (1 + suffixE[i]);
		res = (res + prefixW[i] * temp) % mod;
	}
	cout << res << endl;
}