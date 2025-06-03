#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int LIS(const vector<int>& arr, vector<pair<int, int>>& lisLog)
{
	vector<int> lis;

	for (int num : arr)
	{
		auto it = lower_bound(lis.begin(), lis.end(), num);

		// num보다 작거나 같은 수가 lis에 없다면
		if (it == lis.end())
		{
			lis.push_back(num);
			lisLog.push_back({ num, lis.size() });
		}
		// 아니면 작거나 같은 수 중 가장 오른쪽에 있는 값을 num으로 대체
		else
		{
			*it = num;
			int index = (it - lis.begin()) + 1;
			lisLog.push_back({ num, index });
		}
	}

	return lis.size();
}

int main()

{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<pair<int, int>> lisLog;
	int lisLen = LIS(arr, lisLog);
	cout << lisLen << endl;

	vector<int> realLIS;
	reverse(lisLog.begin(), lisLog.end());
	for (const pair<int, int>& p : lisLog)
	{
		if (p.second == lisLen)
		{
			realLIS.push_back(p.first);
			lisLen--;
		}
	}
	
	reverse(realLIS.begin(), realLIS.end());
	for (int i : realLIS)
	{
		cout << i << ' ';
	}
	cout << endl;
}