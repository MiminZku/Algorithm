#include <iostream>

using namespace std;

int n, m, k;
int skillPlan[100][10];
bool selected[21];
int ans;

void Recur(int level, int start)
{
	if (level == n)
	{
		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			int check = true;
			for (int j = 0; j < k; ++j)
			{
				if (false == selected[skillPlan[i][j]])
				{
					check = false;
					break;
				}
			}
			if (check) ++cnt;
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i = start; i <= 2 * n; ++i)
	{
		selected[i] = true;
		Recur(level + 1, i + 1);
		selected[i] = false;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cin >> skillPlan[i][j];
		}
	}

	Recur(0, 1);

	cout << ans << endl;
}