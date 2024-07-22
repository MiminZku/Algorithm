#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[100000];
int dp[100000][5][5];

// COST[i][j] : i번 지점에서 j번 지점 누를 때 드는 힘
const int COST[5][5] =
{
	{1, 2, 2, 2, 2},
	{3, 1, 3, 4, 3},
	{3, 3, 1, 3, 4},
	{3, 4, 3, 1, 3},
	{3, 3, 4, 3, 1}
};

int Recur(int i, int left, int right)	// i번째 지시사항부터 끝까지 눌렀을 때 최소 비용
{
	if (n == i)	return 0;

	if (dp[i][left][right] != -1)	return dp[i][left][right];
	return dp[i][left][right] = 
		min(COST[left][arr[i]] + Recur(i + 1, arr[i], right),
			COST[right][arr[i]] + Recur(i + 1, left, arr[i]));
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	int k;
	for (int i = 0 ; ; ++i)
	{
		cin >> k;
		if (0 == k)
		{
			n = i;
			break;
		}
		arr[i] = k;
	}

	cout << Recur(0, 0, 0) << endl;
}