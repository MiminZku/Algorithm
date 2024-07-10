#include <iostream>

using namespace std;

int n;
int arr[10][2];
int path[10][2];
int res = 2147483647;

void Recur(int level, int a, int b, int cnt)
{
	if (n == level)
	{
		if(cnt > 0)
			res = min(res, abs(a - b));
		return;
	}

	Recur(level + 1, a * arr[level][0], b + arr[level][1], cnt + 1);
	Recur(level + 1, a, b, cnt);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	Recur(0, 1, 0, 0);

	cout << res << endl;
}