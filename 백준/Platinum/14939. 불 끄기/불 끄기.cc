#include <iostream>

using namespace std;

int n = 10;
int dr[] = { 0, 0, 0, -1, 1 };
int dc[] = { 0, -1, 1, 0, 0 };

int res = 2147483647;
bool light[10][10];
int lightNum;

void Toggle(int r, int c, int& lightNum)
{
	if (light[r][c])	--lightNum;
	else				++lightNum;
	light[r][c] = !light[r][c];
}

void Switch(int r, int c, int& lightNum)
{
	for (int i = 0; i < 5; ++i)
	{
		int nr = dr[i] + r;
		int nc = dc[i] + c;
		if (nr < 0 || nc < 0 || nr >= n || nc >= n)	continue;
		Toggle(nr, nc, lightNum);
	}
}

void Recur(int r, int c, int cnt, int lightNum)
{
	if (n == c)
	{
		c = 0;
		++r;
	}		

	if (0 == r)
	{
		Switch(r, c, lightNum);
		Recur(r, c + 1, cnt + 1, lightNum);
		Switch(r, c, lightNum);

		Recur(r, c + 1, cnt, lightNum);
	}
	else if(n > r)
	{
		if (light[r - 1][c])
		{
			Switch(r, c, lightNum);
			Recur(r, c + 1, cnt + 1, lightNum);
			Switch(r, c, lightNum);
		}
		else
		{
			Recur(r, c + 1, cnt, lightNum);
		}
	}
	else
	{
		if (0 == lightNum)
		{
			res = min(res, cnt);
		}
		return;
	}
}

int main()
{
	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ch;
			if (ch == 'O')
			{
				light[i][j] = true;
				++lightNum;
			}
		}
	}

	Recur(0, 0, 0, lightNum);

	cout << res << endl;
}