#include <iostream>

using namespace std;

int main() 
{
	int x, y;
	cin >> x >> y;
	int ans = 0;
	for(int i=0, j=1; i<x; ++i, j *= 10)
	{
		ans += j;
	}
	for(int i=0, j=1; i<y; ++i, j *= 10)
	{
		ans += j;
	}
	cout << ans << endl;
}