#include <iostream>

using namespace std;

int n;
int arr[30][3];
int target[3];
int path[30];
int res = 1000;
int maxLevel;

void Recur(int level, int start)
{
	if (level == maxLevel)
	{
		int sum[3] = {};
		for (int i = 0; i < level; ++i)
		{
			//cout << path[i] << ' ';
			for (int j = 0; j < 3; ++j)
			{
				sum[j] += arr[path[i]][j];
			}
		}
		//cout << endl;

		int delta = 0;
		for (int i = 0; i < 3; ++i)
		{
			delta += abs((sum[i] / level) - target[i]);
		}
		res = min(res, delta);
		return;
	}

	for (int i = start; i < n; ++i)
	{
		path[level] = i;
		Recur(level + 1, i + 1);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> target[i];
	}

	for (int i = 2; i <= n; ++i)
	{
		if (i > 7)	break;
		maxLevel = i;
		Recur(0, 0);
	}

	cout << res << endl;
}
