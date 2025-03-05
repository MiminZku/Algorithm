#include <iostream>

using namespace std;

int n, x;
int arr[500'000];

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	return GCD(b, a % b);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> x;

	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (1 == GCD(x, arr[i]))
		{
			sum += arr[i];
			++cnt;
		}
	}

	cout << sum / float(cnt) << endl;
}