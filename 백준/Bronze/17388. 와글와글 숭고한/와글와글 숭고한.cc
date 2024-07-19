#include <iostream>

using namespace std;

int s, k, h;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> s >> k >> h;
	int sum = s + k + h;
	if (sum >= 100)	cout << "OK\n";
	else
	{
		if (s < k)
		{
			if (s < h)
			{
				cout << "Soongsil\n";
			}
			else
			{
				cout << "Hanyang\n";
			}
		}
		else
		{
			if (k < h)
			{
				cout << "Korea\n";
			}
			else
			{
				cout << "Hanyang\n";
			}
		}
	}
}