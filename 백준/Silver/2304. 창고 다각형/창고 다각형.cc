#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define L first
#define H second

int n;
vector<pair<int, int>> vec;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	vec.resize(n);

	int maxH = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].L >> vec[i].H;
		if (maxH < vec[i].H)
			maxH = vec[i].H;
	}

	sort(vec.begin(), vec.end());

	int sum = maxH;

	int prevH = vec[0].H;
	int prevL = vec[0].L;

	for (int i = 0; i < n; ++i)
	{
		if (vec[i].H > prevH)
		{
			sum += (vec[i].L - prevL) * prevH;
			prevL = vec[i].L;
			prevH = vec[i].H;
		}
	}

	prevH = vec[n - 1].H;
	prevL = vec[n - 1].L;
	for (int i = n - 1; i >= 0; --i)
	{
		if (vec[i].H > prevH)
		{
			sum += (prevL - vec[i].L) * prevH;
			prevL = vec[i].L;
			prevH = vec[i].H;
		}
	}

	int maxH_L_first = -1;
	int maxH_L_last = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vec[i].H == maxH)
		{
			++cnt;
			if (maxH_L_first < 0)
			{
				maxH_L_first = vec[i].L;
			}
			maxH_L_last = vec[i].L;
		}
	}

	if (cnt > 1)
	{
		sum += (maxH_L_last - maxH_L_first) * maxH;
	}

	cout << sum << endl;
}