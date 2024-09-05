#include <iostream>

using namespace std;

long long G;

int main()
{
	ios::sync_with_stdio(false);

	cin >> G;

	bool exist = false;
	long long s = 1, e = 2;
	while (s < e && e <= 100000)
	{
		long long diff = e * e - s * s;
		if (G < diff)
		{
			++s;
		}
		else if (G > diff)
		{
			++e;
		}
		else
		{
			exist = true;
			cout << e << '\n';
			++s;
			++e;
		}

	}
	if (!exist)	cout << "-1\n";
}