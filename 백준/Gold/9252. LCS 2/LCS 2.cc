#include <iostream>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

string s1, s2;
int dp[1000][1000];

int Recur(int i, int j, int cnt)	// s1의 i번 index부터의 부분문자열과 s2의 j번 index부터의 부분문자열의 LCS 길이
{
	if (s1.size() == i || s2.size() == j)
	{
		return 0;
	}

	if (-1 != dp[i][j])	return dp[i][j];

	if (s1[i] == s2[j])
	{
		return dp[i][j] = Recur(i + 1, j + 1, cnt + 1) + 1;
	}
	return dp[i][j] = max(Recur(i + 1, j, cnt), Recur(i, j + 1, cnt));
}

void Print(int r, int c)
{
	if (s1.size() == r || s2.size() == c)	return;

	if (s1[r] == s2[c])
	{
		cout << s1[r];
		Print(r + 1, c + 1);
	}
	else
	{
		if (dp[r + 1][c] > dp[r][c + 1])	Print(r + 1, c);
		else								Print(r, c + 1);
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> s1 >> s2;

	int lcsLen = Recur(0, 0, 0);
	cout << lcsLen << endl;
	if (lcsLen)
	{
		Print(0, 0);
		cout << endl;
	}
}