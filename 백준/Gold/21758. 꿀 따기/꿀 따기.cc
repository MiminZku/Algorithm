#include <iostream>

using namespace std;

int n;
int arr[100001];
int cumSum[100001];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		cumSum[i] = arr[i] + cumSum[i - 1];
	}

	int ans = 0;
	int temp;
	// 벌통 오른쪽 끝
	for (int i = 2; i <= n; ++i)
	{
		temp = (cumSum[n] - cumSum[1] - arr[i])
			+ (cumSum[n] - cumSum[i]);
		ans = max(ans, temp);
	}
	// 벌통 왼쪽 끝
	for (int i = 1; i < n; ++i)
	{
		temp = (cumSum[n - 1] - cumSum[0] - arr[i])
			+ (cumSum[i - 1] - cumSum[0]);
		ans = max(ans, temp);
	}
	// 벌통 중간
	for (int i = 2; i < n; ++i)
	{
		temp = 2 * arr[i] + (cumSum[i - 1] - cumSum[1]) + (cumSum[n - 1] - cumSum[i]);
		ans = max(ans, temp);
	}

	cout << ans << endl;
}