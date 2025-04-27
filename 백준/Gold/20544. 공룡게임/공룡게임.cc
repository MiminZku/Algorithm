#include <iostream>
#include <memory.h>

#define MOD 1'000'000'007;

using namespace std;

int n;
int memo[1000][3][1000][3];

// idx : 현재 좌표
// state : 지점의 상태 (0 = 바닥, 1 or 2 = 선인장) 
// num : 높이 2인 선인장 개수
// con : 지금까지 연속한 선인장 개수
int Recur(int idx, int state, int num, int con)
{
	if (idx == n)
	{
		if (num == 0)	return 0;
		return 1;
	}

	if (memo[idx][state][num][con] != -1)
	{
		return memo[idx][state][num][con];
	}

	if (con == 2)
	{
		return memo[idx][state][num][con] = Recur(idx + 1, 0, num, 0) % MOD;
	}

	int ret = 0;
	for (int s = 0; s < 3; ++s)
	{
		if (s == 2 && state == 2)	break;
		ret += Recur(idx + 1, s, num + (s == 2), (s == 0) ? 0 : con + 1) % MOD;
	    ret %= MOD;
    }

	return memo[idx][state][num][con] = ret;
}

int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n;

	cout << Recur(1, 0, 0, 0) << endl;
}