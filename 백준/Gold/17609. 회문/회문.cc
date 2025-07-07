#include <iostream>

using namespace std;

int Solve(const string& str, int l, int r, bool deleted)
{
	if (l >= r)
	{
		return deleted ? 1 : 0;
	}

	if (str[l] == str[r])
	{
		return Solve(str, l + 1, r - 1, deleted);
	}

	if (deleted)
	{
		return 2;
	}

	return min(Solve(str, l + 1, r, true), Solve(str, l, r - 1, true));
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	cin.ignore();
	string str;
	while (t--)
	{
		cin >> str;

		cout << Solve(str, 0, str.length() - 1, 0) << '\n';
	}
}