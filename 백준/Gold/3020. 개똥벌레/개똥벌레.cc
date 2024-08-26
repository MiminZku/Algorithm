#include <iostream>

using namespace std;

int n, h;
int cumSum[500005];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> h;
	for (int i = 1, k; i <= n; ++i)
	{
		cin >> k;
		if (i % 2)
		{
			cumSum[1] += 1;
			cumSum[1 + k] -= 1;
		}
		else
		{
			cumSum[h + 1 - k] += 1;
			//cumSum[h + 1] -= 1;
		}
	}

	int obstacleNum = 2147483647, ansNum = 0;
	for (int i = 1; i <= h; ++i)
	{
		cumSum[i] += cumSum[i - 1];
		//cout << cumSum[i] << ' ';
		if (obstacleNum > cumSum[i])
		{
			obstacleNum = cumSum[i];
			ansNum = 1;
		}
		else if (obstacleNum == cumSum[i])
		{
			++ansNum;
		}
	}
	cout << obstacleNum << ' ' << ansNum << endl;
}