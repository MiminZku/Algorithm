#include <iostream>
#include <memory.h>

using namespace std;

int n;
int a, b;
int satisfaction[100][4];
int dp[100][100][100][2];

// 날, 정독실이나 소학습실에서 자습한 회수, 요양신청 횟수, 휴게실 연속
int Recur(int day, int studyCnt, int restCnt, int cont)	
{
	if(restCnt > a || cont > 1)	return -2147483648;
	if (day == n)
	{
		if (studyCnt < b)	return -2147483648;
		return 0;
	}

	if (dp[day][studyCnt][restCnt][cont] != -1) return dp[day][studyCnt][restCnt][cont];

	int temp = -2147483648;
	for (int i = 0; i < 4; ++i)
	{
		temp = max(temp, 
			Recur(day + 1, studyCnt + (i < 2), restCnt + (i == 3), (i == 2) ? cont + 1 : 0) 
			+ satisfaction[day][i]);
	}

	return dp[day][studyCnt][restCnt][cont] = temp;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cin >> satisfaction[i][j];
		}
	}

	cout << Recur(0, 0, 0, 0) << endl;
}