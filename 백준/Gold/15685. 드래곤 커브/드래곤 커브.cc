#include <iostream>
#include <vector>

using namespace std;

int n, x, y, d, g;
bool board[101][101];

int CountSquare()
{
	int ret = 0;

	int dy[] = { 0,0,1,1 };
	int dx[] = { 0,1,0,1 };

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			bool check = true;
			for (int k = 0; k < 4; ++k)
			{
				int y = i + dy[k];
				int x = j + dx[k];
				if (board[y][x] == false)
				{
					check = false;
					break;
				}
			}

			if (check)
			{
				ret++;
			}
		}
	}

	return ret;
}

void DrawCurve(vector<pair<int, int>>& points, int gen)
{
	if (gen == g)
	{
		return;
	}

	pair<int, int> lastPoint = points.back();

	int len = points.size();
	for (int i = len - 2; i >= 0; --i)
	{
		int dx = points[i].first - lastPoint.first;
		int dy = points[i].second - lastPoint.second;

		if (dy != 0)
		{
			swap(dx, dy);
			dx *= -1;
		}
		else
		{
			swap(dx, dy);
		}

		points.push_back({ lastPoint.first + dx, lastPoint.second + dy });
	}

	DrawCurve(points, gen + 1);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> d >> g;

		int x1 = x, y1 = y;
		if (d == 0)
		{
			x1 = x + 1;
		}
		else if (d == 1)
		{
			y1 = y - 1;
		}
		else if (d == 2)
		{
			x1 = x - 1;
		}
		else if (d == 3)
		{
			y1 = y + 1;
		}
		vector<pair<int, int>> points;
		points.push_back({ x, y });
		points.push_back({ x1, y1 });

		DrawCurve(points, 0);

		for (auto& p : points)
		{
			board[p.second][p.first] = true;
		}
	}

	cout << CountSquare() << endl;
}