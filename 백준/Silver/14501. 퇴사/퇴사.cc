#include <iostream>

using namespace std;

int n;
pair<int, int> arr[15];
int ans;

void Recur(int day, int total)
{
	if (day == n)
	{
		ans = max(ans, total);
		return;
	}
	if (day > n)	return;

	// 이 날 일을 선택할 경우
	Recur(day + arr[day].first, total + arr[day].second);

	// 이날 일을 선택 안할 경우
	Recur(day + 1, total);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;

	Recur(0, 0);

	cout << ans << endl;
}