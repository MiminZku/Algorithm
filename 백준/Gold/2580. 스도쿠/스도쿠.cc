#include <iostream>

using namespace std;

bool usedRow[9][10];
bool usedCol[9][10];
bool usedBox[9][10];

int board[81];

int BoxNum(int r, int c)
{
	return (r / 3) * 3 + (c / 3);
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
				cout << board[i * 9 + j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	if (0 != board[r * 9 + c])
	{
		Recur(r, c + 1);
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (usedRow[r][i] ||
			usedCol[c][i] ||
			usedBox[BoxNum(r, c)][i])
		{
			continue;
		}
		usedRow[r][i] = true;
		usedCol[c][i] = true;
		usedBox[BoxNum(r, c)][i] = true;
		board[r * 9 + c] = i;

		
		Recur(r, c + 1);

		usedRow[r][i] = false;
		usedCol[c][i] = false;
		usedBox[BoxNum(r, c)][i] = false;
		board[r * 9 + c] = 0;
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
			board[i * 9 + j] = k;

			usedRow[i][k] = true;
			usedCol[j][k] = true;
			usedBox[BoxNum(i, j)][k] = true;
		}
	}

	Recur(0, 0);
}