#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

	int t, h, w, ans = 0;
	cin >> t;
	while(t--)
	{
		cin >> h >> w;
		ans = max(ans, h * w);
	}

	cout << ans << endl;
}