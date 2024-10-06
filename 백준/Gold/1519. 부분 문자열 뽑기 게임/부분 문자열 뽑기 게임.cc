#include <iostream>
#include <set>
#include <string>
#include <memory.h>

using namespace std;

int n;
int canWin[1'000'001];

void ReturnSubStrs(const string& orgStr, set<int>& strArr)
{
	string subStr;
	for (int i = 0; i < orgStr.size(); ++i)
	{
		for (int j = 1; j < orgStr.size(); ++j)
		{
			subStr = orgStr.substr(i, j);
			int num = stoi(subStr);
			if (num > 0)
			{
				strArr.insert(num);
			}
		}
	}
}

//int Recur(int  num)	// 현재 숫자가 num일 때 이길 수 있는 부분 문자열 중 가장 작은 수, 0이면 무조건 패배
//{
//	if (num < 10)	return 0;	// 한자리 숫자면 무조건 패배
//	if (canWin[num] != -1)	return canWin[num];
//
//	set<int> subStrs;
//	ReturnSubStrs(to_string(num), subStrs);
//	for (int i : subStrs)
//	{
//		if (0 == Recur(num - i))
//		{
//			return canWin[num] = i;
//		}
//	}
//	return canWin[num] = 0;
//}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	memset(canWin, -1, sizeof(canWin));

	for (int num = 10; num <= n; ++num)
	{
		int res = -1;
		set<int> subStrs;
		ReturnSubStrs(to_string(num), subStrs);
		for (int i : subStrs)
		{
			if (-1 == canWin[num - i])
			{
				res = i;
				break;
			}
		}
		canWin[num] = res;
	}
	cout << canWin[n] << endl;
}