#include <iostream>

using namespace std;

int n;
int arr[2020];
int cumSum[2020];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		cumSum[i] = cumSum[i - 1] + arr[i];
	}

	int minDiff = 2147483647;
	int ans = 0;
	for (int mid = 1; mid < n; ++mid)
	{
		int s = mid, e = mid + 1;
		while (s > 0 && e <= n)
		{
			int leftSum = cumSum[mid] - cumSum[s - 1];
			int rightSum = cumSum[e] - cumSum[mid];
			int diff = abs(leftSum - rightSum);


			if (diff <= minDiff)
			{
				if (diff < minDiff)
                {
				    minDiff = diff;                    
					ans = cumSum[e] - cumSum[s - 1];
                }
				else
                {
					ans = max(ans, cumSum[e] - cumSum[s - 1]);
                }
			}

			if (leftSum > rightSum)
			{
				++e;
			}
			else if (leftSum < rightSum)
			{
				--s;
			}
			else
			{
				--s;
				++e;
			}

		}
	}
	cout << ans << endl;
}