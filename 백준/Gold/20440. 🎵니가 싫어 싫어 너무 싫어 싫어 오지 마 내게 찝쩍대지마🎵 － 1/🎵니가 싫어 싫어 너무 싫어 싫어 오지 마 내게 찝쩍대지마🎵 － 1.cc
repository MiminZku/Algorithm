#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<pair<int, int>> pArr(n);
	vector<int> coords;
	for (int i = 0; i < n; ++i)
	{
		cin >> pArr[i].first >> pArr[i].second;
		coords.push_back(pArr[i].first);
		coords.push_back(pArr[i].second);
	}

	sort(coords.begin(), coords.end());
	coords.erase(unique(coords.begin(), coords.end()), coords.end());

	vector<int> cumSum(coords.size() + 1);
	for (int i = 0; i < n; ++i)
	{
		int s = lower_bound(coords.begin(), coords.end(), pArr[i].first) - coords.begin();
		int e = lower_bound(coords.begin(), coords.end(), pArr[i].second) - coords.begin();
		cumSum[s]++;
		cumSum[e]--;
	}
	int maxCnt = cumSum[0];
	for (int i = 1; i < cumSum.size(); ++i)
	{
		cumSum[i] += cumSum[i - 1];
		maxCnt = max(maxCnt, cumSum[i]);
	}
	cout << maxCnt << endl;

	int maxTime = 0;
	pair<int, int> ans;
	for (int i = 0, time = 0; i <= cumSum.size(); ++i)
	{
		if (i == cumSum.size() || cumSum[i] != maxCnt)
		{
			if (maxTime < time)
			{
				ans.first = i - time;
				ans.second = i;
				maxTime = time;
			}
			time = 0;
		}
		else
		{
			time++;
		}
	}
	cout << coords[ans.first] << ' ' << coords[ans.second] << endl;
}