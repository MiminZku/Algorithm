#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

	pair<int, int> ans;
	int minY = 10000;
	int n, x, y;
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		if(y < minY)
		{
			minY = y;
			ans = {x, y};
		}
	}

	cout << ans.first << ' ' << ans.second << endl;
}