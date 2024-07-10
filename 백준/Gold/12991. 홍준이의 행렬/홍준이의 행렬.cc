#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arrA[30000];
int arrB[30000];
int maxA, maxB;

long long Check(long long num)
{
	long long cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		long long a = arrA[i];

		long long target = num / arrA[i];
		long long s = 0, e = n - 1;

		while (s <= e)
		{
			long long mid = (s + e) / 2;
			if (arrB[mid] <= target)
			{
				s = mid + 1;
			}
			else
			{
				e = mid - 1;
			}
		}
		cnt += s;
	}
	return cnt;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> arrA[i];
		maxA = max(maxA, arrA[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arrB[i];
		maxB = max(maxB, arrB[i]);
	}
	sort(arrA, arrA + n);
	sort(arrB, arrB + n);

	long long s = 1, e = (long long)maxA * maxB;

	while (s <= e)
	{
		long long mid = (s + e) / 2;

		if (Check(mid) < k)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}

	cout << s << endl;
}