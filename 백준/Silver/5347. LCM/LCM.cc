#include <iostream>

using namespace std;

int n;

int GCD(int a, int b)
{
	int l = a % b;
	if (l == 0)
	{
		return b;
	}
	return GCD(b, l);
}

long long LCM(long long a, long long b)	// GCD가 1일수도 있음
{
	return a / GCD(a, b) * b;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;

	int a, b;
	while (n--)
	{
		cin >> a >> b;
		cout << LCM(a, b) << '\n';
	}
}