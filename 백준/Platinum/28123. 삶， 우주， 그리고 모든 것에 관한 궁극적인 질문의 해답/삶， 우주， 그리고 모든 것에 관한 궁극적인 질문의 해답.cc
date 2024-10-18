#include <iostream>

using namespace std;

long long n, k;
int x;

int p[10] = { 0, 1, 2, 2, 3, 3, 3, 3, 4, 4 };

int main()
{
	cin >> n >> k >> x;
	cout << (n + 1 - p[x]) - 3 * (k - 1) + (x == 4 || x == 8 || x == 9) << endl;	
}
