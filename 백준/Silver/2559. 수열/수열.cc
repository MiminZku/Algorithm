#include <iostream>

using namespace std;

int n, k;
int cumSum[100001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int m;
		cin >> m;
		cumSum[i] = cumSum[i - 1] + m;
	}

	int maxNum = -2147483648;
	for (int i = 0; i <= n - k; ++i)
	{
		int temp = cumSum[i + k] - cumSum[i];
		maxNum = max(maxNum, temp);
	}
	cout << maxNum << endl;
}