#include <iostream>

using namespace std; 

#define ld long double

int n;
pair<ld, ld> pos[10001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	ld offsetX, offsetY;
	cin >> offsetX >> offsetY;
	for (int i = 1; i < n; ++i)
	{
		cin >> pos[i].first >> pos[i].second;
		pos[i].first -= offsetX;
		pos[i].second -= offsetY;
	}

	ld sum = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		sum += pos[i].first * pos[i + 1].second - pos[i].second * pos[i + 1].first;
	}
	sum /= 2;
	sum = abs(sum);

	cout << fixed;
	cout.precision(1);
	cout << sum << endl;
}