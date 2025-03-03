#include <iostream>

using namespace std;

int t;

int GCD(int a, int b)
{
	int l = a % b;
	if (l == 0)
	{
		return b;
	}
	return GCD(b, l);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> t;
	
	int n;
	int arr[100];

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		long long sum = 0;    // 개별 100만
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				sum += GCD(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
}