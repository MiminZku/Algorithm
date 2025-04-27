#include <iostream>
#include <memory.h>

#define MOD 1'000'000'007;

using namespace std;

int n;
int memo[1000][3][3][2];

// idx : 현재 좌표
// state : 지점의 상태 (0 = 바닥, 1 or 2 = 선인장) 
// con : 지금까지 연속한 선인장 개수
// check : 높이 2인 선인장 있는지
int Recur(int idx, int state, int con, bool check)
{
	if (idx == n)
	{
		if (check == false)	return 0;
		return 1;
	}

	if (memo[idx][state][con][check] != -1)
	{
		return memo[idx][state][con][check];
	}

	if (con == 2)
	{
		return memo[idx][state][con][check] = Recur(idx + 1, 0, 0, check) % MOD;
	}

	int ret = 0;
	for (int s = 0; s < 3; ++s)
	{
		if (s == 2 && state == 2 && con == 1)	break;
		ret += Recur(idx + 1, s, (s == 0) ? 0 : con + 1, check || (s == 2)) % MOD;
		ret %= MOD;
	}

	return memo[idx][state][con][check] = ret % MOD;
}

int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n;

	cout << Recur(1, 0, 0, 0) << endl;
}