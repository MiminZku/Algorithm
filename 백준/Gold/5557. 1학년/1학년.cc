#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n;
vector<int> arr;
int target;
long long memo[100][21];

long long Recur(int idx, int total)
{
	if (idx >= n - 1)
	{
		if (total == target)
		{
			return 1;
		}
		return 0;
	}

	if (memo[idx][total] != -1)
	{
		return memo[idx][total];
	}

	long long ret = 0;
	if (total + arr[idx] <= 20)
	{
		ret += Recur(idx + 1, total + arr[idx]);
	}
	if (total - arr[idx] >= 0)
	{
		ret += Recur(idx + 1, total - arr[idx]);
	}

	return memo[idx][total] = ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n;
	arr.resize(n - 1);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> arr[i];
	}
	cin >> target;

	cout << Recur(1, arr[0]) << endl;
}