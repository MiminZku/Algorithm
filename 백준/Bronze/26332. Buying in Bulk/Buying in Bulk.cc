#include <iostream>

using namespace std;

int main() 
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while(n--)
	{
		int c, p;
		cin >> c >> p;
		int ans = c * p;
		ans -= (c - 1) * 2;
		cout << c << ' ' << p << '\n';
		cout << ans << '\n';
	}
}