#include <iostream>

using namespace std;

bool usedRow[9][10];
bool usedCol[9][10];
bool usedBox[9][10];

int board[9][9];

int BoxNum(int r, int c)
{
	return (r / 3) * 3 + (c / 3);
}

void CheckUsed(int r, int c, int num, bool used)
{
	usedRow[r][num] = used;
	usedCol[c][num] = used;
	usedBox[BoxNum(r, c)][num] = used;
	board[r][c] = used ? num : 0;
}

void Recur(int r, int c)
{
	if (9 == c)
	{
		c = 0;
		r += 1;
	}
	if (9 == r)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	if (0 != board[r][c])
	{
		Recur(r, c + 1);
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (usedRow[r][i] || usedCol[c][i] || usedBox[BoxNum(r, c)][i])
		{
			continue;
		}
		CheckUsed(r, c, i, true);
		Recur(r, c + 1);
		CheckUsed(r, c, i, false);
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int k;
			cin >> k;
			CheckUsed(i, j, k, true);
		}
	}

	Recur(0, 0);
}