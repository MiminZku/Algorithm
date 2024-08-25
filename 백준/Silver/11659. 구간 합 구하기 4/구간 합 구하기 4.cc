#include <iostream>

using namespace std;

int n, m;
int cumSum[100001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		cumSum[i] = cumSum[i - 1] + k;
	}

	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << cumSum[j] - cumSum[i - 1] << '\n';
	}
}