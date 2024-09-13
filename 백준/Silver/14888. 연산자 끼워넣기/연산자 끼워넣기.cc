#include <iostream>

using namespace std;

int n;
int arr[11];
int num[4];
int minRes = 2147483647;
int maxRes = -2147483648;

void Recur(int level, int total)
{
	if (level == n)
	{
		minRes = min(minRes, total);
		maxRes = max(maxRes, total);
		return;
	}

	for (int op = 0; op < 4; ++op)
	{
		if (num[op] <= 0)	continue;
		--num[op];
		int temp;
		if (op == 0) temp = total + arr[level];
		else if (op == 1) temp = total - arr[level];
		else if (op == 2) temp = total * arr[level];
		else if (op == 3) temp = total / arr[level];
		Recur(level + 1, temp);
		++num[op];
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> arr[i];
	for (int i = 0; i < 4; ++i)	cin >> num[i];

	Recur(1, arr[0]);

	cout << maxRes << endl << minRes << endl;
}