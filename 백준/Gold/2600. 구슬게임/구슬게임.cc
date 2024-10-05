#include <iostream>
#include <memory.h>

using namespace std;

int b[3];
int k1, k2;
int canWin[500][500];

bool Recur(int m1, int m2)	// 첫번째 통 구슬 개수, 두번째 통 구슬 개수 남은 상태일 때 이길 수 있는지
{
	if (m1 == 0 && m2 == 0)	return false;
	if (canWin[m1][m2] != -1)	return canWin[m1][m2];

	// 6가지 경우 중 상대가 이길 수 없는 경우가 하나라도 있으면 승리
	bool ret = false;
	for (int i = 0; i < 3; ++i)
	{
		if (m1 - b[i] < 0)	continue;
		if (false == Recur(m1 - b[i], m2))
		{
			ret = true;
			break;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (m2 - b[i] < 0)	continue;
		if (false == Recur(m1, m2 - b[i]))
		{
			ret = true;
			break;
		}
	}

	return canWin[m1][m2] = ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(canWin, -1, sizeof(canWin));

	for (int i = 0; i < 3; ++i)	cin >> b[i];
	int t = 5;
	while (t--)
	{
		cin >> k1 >> k2;
		cout << (Recur(k1, k2) ? "A" : "B") << endl;
	}
}