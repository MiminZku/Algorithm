#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	priority_queue<int, vector<int>, greater<int>> lectureEnds;
	lectureEnds.push(0);

	for (const auto& l : arr)
	{
		int start = l.first;
		int end = l.second;

		if (lectureEnds.top() <= start)
		{
			lectureEnds.pop();
		}

		lectureEnds.push(end);
	}

	cout << lectureEnds.size() << endl;
}