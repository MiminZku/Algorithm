#include <iostream>

#define Y first
#define X second 

using namespace std;

int mat[8][7];
bool isFilled[8][7];
bool isUsed[7][7];

int ans;

void Recur(int row, int col)
{
	if (7 <= col)
	{
		col = 0;
		++row;
	}
	if (8 == row)
	{
		++ans;
		return;
	}

	pair<int, int> cell1 = { row, col };
	int cell1Num = mat[cell1.Y][cell1.X];

	if (isFilled[cell1.Y][cell1.X])
	{
		Recur(row, col + 1);
		return;
	}

	// 가로로 놓음
	pair<int, int> cell2 = { row, col + 1 };
	int cell2Num = mat[cell2.Y][cell2.X];
	
	if (cell2.X  < 7 && !isFilled[cell2.Y][cell2.X])
	{		
		if (!isUsed[cell1Num][cell2Num])
		{
			isFilled[cell1.Y][cell1.X] = true;
			isFilled[cell2.Y][cell2.X] = true;
			
			isUsed[cell1Num][cell2Num] = true;
			isUsed[cell2Num][cell1Num] = true;

			Recur(row, col + 2);

			isUsed[cell1Num][cell2Num] = false;
			isUsed[cell2Num][cell1Num] = false;

			isFilled[cell1.Y][cell1.X] = false;
			isFilled[cell2.Y][cell2.X] = false;
		}
	}

	// 세로로 놓음
	cell2 = { row + 1, col };

	if (cell2.Y < 8)
	{
		cell2Num = mat[cell2.Y][cell2.X];
		if (!isUsed[cell1Num][cell2Num])
		{
			isFilled[cell1.Y][cell1.X] = true;
			isFilled[cell2.Y][cell2.X] = true;

			isUsed[cell1Num][cell2Num] = true;
			isUsed[cell2Num][cell1Num] = true;

			Recur(row, col + 1);

			isUsed[cell1Num][cell2Num] = false;
			isUsed[cell2Num][cell1Num] = false;

			isFilled[cell1.Y][cell1.X] = false;
			isFilled[cell2.Y][cell2.X] = false;
		}
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			char ch;
			cin >> ch;
			mat[i][j] = ch - '0';
		}
	}

	Recur(0, 0);

	cout << ans << endl;
}