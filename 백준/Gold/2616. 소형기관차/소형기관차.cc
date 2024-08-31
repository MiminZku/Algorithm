#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[50001];
int preSum[50001];
int m;
int dp[50001][3];

int Recur(int idx, int cnt)
{
	if (3 == cnt)	return 0;
	if (idx > n)	return -2147483648;

	if (-1 != dp[idx][cnt])	return dp[idx][cnt];

	int temp = 0;
	// idx번 칸 고르는 경우
	if(idx + m - 1 <= n)
		temp = Recur(idx + m, cnt + 1) + preSum[idx + m - 1] - preSum[idx - 1];

	// 안 고르는 경우
	temp = max(temp, Recur(idx + 1, cnt));

	return dp[idx][cnt] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		preSum[i] = preSum[i - 1] + arr[i];
	}
	cin >> m;

	cout << Recur(1, 0) << endl;
}