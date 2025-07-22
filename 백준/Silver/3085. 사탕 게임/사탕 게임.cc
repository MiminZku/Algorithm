#include <iostream>

using namespace std;

int n;
int mat[50][50];
int ans;

int Calculate()
{
	int maxCnt = 1;
	for (int i = 0; i < n; ++i)
	{
		int row = 1, col = 1;
		for (int j = 1; j < n; ++j)
		{
			if (mat[i][j] == mat[i][j - 1])
			{
				row++;
			}
			else
			{
				row = 1;
			}
			maxCnt = max(maxCnt, row);

			if (mat[j][i] == mat[j - 1][i])
			{
				col++;
			}
			else
			{
				col = 1;
			}
			maxCnt = max(maxCnt, col);
		}
	}
	return maxCnt;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	cin.ignore();
	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ch;
			if (ch == 'C')		mat[i][j] = 0;
			else if (ch == 'P') mat[i][j] = 1;
			else if (ch == 'Z') mat[i][j] = 2;
			else if (ch == 'Y') mat[i][j] = 3;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j + 1 < n)
			{
				swap(mat[i][j], mat[i][j + 1]);
				ans = max(ans, Calculate());
				swap(mat[i][j], mat[i][j + 1]);
			}

			if (i + 1 < n)
			{
				swap(mat[i][j], mat[i + 1][j]);
				ans = max(ans, Calculate());
				swap(mat[i][j], mat[i + 1][j]);
			}
		}
	}

	cout << ans << endl;
}