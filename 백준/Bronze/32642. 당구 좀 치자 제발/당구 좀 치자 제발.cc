#include <iostream>

using namespace std;

int main() 
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	long long rage = 0, ans = 0;
	cin >> n;
	for(int i=0, k; i<n; ++i)
	{
		cin >> k;
		rage += k ? 1 : -1;
		ans += rage;
	}

	cout << ans << endl;
}