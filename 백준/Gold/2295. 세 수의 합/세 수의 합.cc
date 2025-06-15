#include <iostream>
#include <algorithm>

using namespace std;

int n;
int nums[1000];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums, nums + n);

	int targetIdx = n - 1;
	while (true)
	{
		int targetNum = nums[targetIdx];
		for (int i = 0; i < targetIdx; ++i)
		{
			int l = i;
			int r = targetIdx - 1;
			while (l <= r)
			{
				int sum = nums[i] + nums[l] + nums[r];
				if (sum > targetNum)
				{
					r--;
				}
				else if (sum < targetNum)
				{
					l++;
				}
				else
				{
					cout << targetNum << endl;
					return 0;
				}
			}
		}
		targetIdx--;
	}
}