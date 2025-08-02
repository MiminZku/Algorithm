#include <iostream>

using namespace std;

int n, m;
int mat[1000][1000];
int memo[1000][1000];
int maxLen;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ch;
			mat[i][j] = ch - '0';
			memo[i][j] = mat[i][j];
			maxLen = max(maxLen, mat[i][j]);
		}
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			if (memo[i][j] == 0)	continue;

			memo[i][j] = 1 +
				min({ memo[i - 1][j - 1], memo[i - 1][j], memo[i][j - 1] });
			maxLen = max(maxLen, memo[i][j]);
		}
	}

	cout << maxLen * maxLen << endl;
}