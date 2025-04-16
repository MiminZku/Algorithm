#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int mat[25][25];

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int Paint(int y, int x, int color)
{
	mat[y][x] = color;
	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
		if (mat[ny][nx] != -1)	continue;
		ret += Paint(ny, nx, color);
	}
	return ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	cin.ignore();
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			mat[i][j] = (str[j] - '0') * -1;
		}
	}

	vector<int> arr;
	for (int i = 0, color = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mat[i][j] != -1)	continue;
			arr.push_back(Paint(i, j, ++color));
		}
	}

	sort(arr.begin(), arr.end());

	cout << arr.size() << endl;
	for (int i : arr)
	{
		cout << i << '\n';
	}
}