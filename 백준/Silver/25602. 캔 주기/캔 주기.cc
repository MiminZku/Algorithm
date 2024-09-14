#include <iostream>

using namespace std;

int n, k;
int canNum[5];
int r[4][5];
int m[4][5];
int ans;

void Recur(int day, int total)
{
	if (day == k)
	{
		ans = max(ans, total);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (canNum[i] <= 0) continue;
		canNum[i]--;
		for (int j = 0; j < n; ++j)
		{
			if (canNum[j] <= 0) continue;
			canNum[j]--;
			Recur(day + 1, total + r[day][i] + m[day][j]);
			canNum[j]++;
		}
		canNum[i]++;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)	cin >> canNum[i];
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)	cin >> r[i][j];
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n; ++j)	cin >> m[i][j];
	}

	Recur(0, 0);

	cout << ans << endl;
}