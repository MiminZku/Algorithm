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
	vector<int> weight(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i];
	}
	sort(weight.begin(), weight.end());

	int target = 1;
	for (int w : weight)
	{
		if (w > target)
		{
			break;
		}
		target += w;
	}
	cout << target;
}