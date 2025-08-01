#include <iostream>

using namespace std;

#define X first
#define Y second

pair<int, int> p[3];
pair<int, int> vec[2];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; ++i)
	{
		cin >> p[i].X >> p[i].Y;
	}

	vec[0] = { p[1].X - p[0].X, p[1].Y - p[0].Y };
	vec[1] = { p[2].X - p[0].X, p[2].Y - p[0].Y };

	int crossZ = vec[0].X * vec[1].Y - vec[1].X * vec[0].Y;

	if (crossZ < 0)
	{
		cout << "-1\n";
	}
	else if (crossZ > 0)
	{
		cout << "1\n";
	}
	else
	{
		cout << "0\n";
	}
}