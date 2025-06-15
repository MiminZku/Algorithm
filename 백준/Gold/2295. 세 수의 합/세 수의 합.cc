#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> nums;
vector<int> sums;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sums.push_back(nums[i] + nums[j]);
		}
	}
	sort(sums.begin(), sums.end());

	int targetIdx = n - 1;
	while (true)
	{
		int targetNum = nums[targetIdx];
		for (int i = 0; i < targetIdx; ++i)
		{
			if (binary_search(sums.begin(), sums.end(), targetNum - nums[i]))
			{
				cout << targetNum << endl;
				return 0;
			}
		}
		targetIdx--;
	}
}