#include <iostream>

using namespace std;

int n, m, k;
bool board[2000][2000];

bool sample1[2000][2000];
bool sample2[2000][2000];

int diffSum1[2002][2002];
int diffSum2[2002][2002];


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (int i = 0, b = 0; i < n; ++i)
	{
		if (m % 2 == 0)
		{
			b = (b + 1) % 2;
		}
		for (int j = 0; j < m; ++j, b = (b + 1) % 2)
		{
			sample1[i][j] = b;
			sample2[i][j] = !b;
		}
	}

	cin.ignore();
	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ch;
			board[i][j] = (ch == 'W');
		}
	}

	int ans = 5000000;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			bool diff1 = board[i - 1][j - 1] == sample1[i - 1][j - 1];
			diffSum1[i][j] = diff1 + diffSum1[i - 1][j] + diffSum1[i][j - 1] - diffSum1[i - 1][j - 1];

			bool diff2 = board[i - 1][j - 1] == sample2[i - 1][j - 1];
			diffSum2[i][j] = diff2 + diffSum2[i - 1][j] + diffSum2[i][j - 1] - diffSum2[i - 1][j - 1];

			if (i < k || j < k)	continue;
			int diff = diffSum1[i][j] - diffSum1[i - k][j] - diffSum1[i][j - k] + diffSum1[i - k][j - k];
			diff = min(diff,
				diffSum2[i][j] - diffSum2[i - k][j] - diffSum2[i][j - k] + diffSum2[i - k][j - k]);
			ans = min(ans, diff);
		}
	}
	cout << ans << endl;
}