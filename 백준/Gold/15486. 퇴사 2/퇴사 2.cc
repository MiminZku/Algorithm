#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> dp;

int Recur(int day)
{
	if (day == n)	return 0;
	if (day > n)	return -2147483648;
	if (dp[day] != -1)	return dp[day];

	int temp = 0;
	// 이 날 일을 선택할 경우
	temp = Recur(day + arr[day].first) + arr[day].second;

	int temp2 = 0;
	// 이날 일을 선택 안할 경우
	temp2 = Recur(day + 1);

	return dp[day] = max(temp, temp2);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	arr.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; ++i)	dp[i] = -1;
	for (int i = 0; i < n; ++i) 
		cin >> arr[i].first >> arr[i].second;

	cout << Recur(0) << endl;
}