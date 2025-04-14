#include <iostream>

using namespace std;

int n;
int arr[1000];
int memo[1000];

int LIS(int idx)	// idx 인덱스부터 끝까지의 LIS
{
	if (memo[idx] != 0) return memo[idx];

	int tmp = 1;
	for (int i = idx + 1; i < n; ++i)
	{
		if (arr[i] > arr[idx])
		{
			tmp = max(tmp, 1 + LIS(i));
		}
	}

	return memo[idx] = tmp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int lisLen = 0;
	for (int i = 0; i < n; ++i)
	{
		lisLen = max(lisLen, LIS(i));
	}

	cout << lisLen << endl;

	for (int i = 0; i < n; ++i)
	{
		if (lisLen == memo[i])
		{
			cout << arr[i] << ' ';
			lisLen--;
		}
	}
	cout << endl;
}