#include <iostream>
#include <memory.h>

using namespace std;

int t;
int n;
int arr[1000];
int dp[1000][1000];

/*
근우 차례 : 점수가 더 높은 카드를 갖고 감으로써 점수를 최대로 하는 플레이를 해야 함

명우 차례 : 명우 입장에선 자신이 이기기 위해 점수가 더 높은 카드를 갖고 갈 것이므로 
			근우는 근우의 점수를 최소로 하는 플레이를 해야 함
*/
int Recur(int l, int r, bool turn)	// 카드가 l 인덱스부터 r 인덱스까지 남아있을 때 얻는 최대 점수
{
	if (l > r)	return 0;	// 남은 카드가 없을 때

	if (dp[l][r] != -1)	return dp[l][r];

	int temp;
	if (turn)
	{
		temp = max(Recur(l + 1, r, !turn) + arr[l], Recur(l, r - 1, !turn) + arr[r]);
	}
	else
	{
		temp = min(Recur(l + 1, r, !turn), Recur(l, r - 1, !turn));
	}

	return dp[l][r] = temp;
}


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; ++i)	cin >> arr[i];

		cout << Recur(0, n - 1, true) << '\n';
		
	}
}