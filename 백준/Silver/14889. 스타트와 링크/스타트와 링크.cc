#include <iostream>

using namespace std;

int n;
int s[20][20];
int res = 2147483647;
int path[10];

void Recur(int level, int start)
{
	if (level == n / 2)
	{
		int startTotal = 0;
		for (int i = 0; i < level; ++i)
		{
			for (int j = 0; j < level; ++j)
			{
				startTotal += s[path[i]][path[j]];
			}
		}

		int path2[10] = {};
		for (int i = 0, idx = 0; i < n; ++i)
		{
			bool isInPath = false;
			for (int j = 0; j < level; ++j)
			{
				if (path[j] == i)
				{
					isInPath = true;
					break;
				}
			}

			if (isInPath == false)
			{
				path2[idx++] = i;
			}
		}

		int linkTotal = 0;
		for (int i = 0; i < level; ++i)
		{
			for (int j = 0; j < level; ++j)
			{
				linkTotal += s[path2[i]][path2[j]];
			}
		}

		res = min(res, abs(startTotal - linkTotal));
		
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
		for (int j = 0; j < n; ++j)
		{
			cin >> s[i][j];
		}
	}

	Recur(0, 0);

	cout << res << endl;
}