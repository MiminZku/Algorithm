#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int n, k;
bool cantUse[100001];
int canWin[100001];	// canWin[i] : i번 숫자를 외쳤을 때 이길 수 있는지

bool Recur(int num, bool isFirst)
{
	if (num > n)	return false;

	if (canWin[num] != -1)	return canWin[num];

	bool ret = true;
	for (int i = num + 1; i <= min(num + k, n); ++i)
	{
		if (cantUse[i]) continue;
		bool temp = Recur(i, !isFirst);
		if (temp)	// 상대가 이기는 경우가 하나라도 있으면 패배
		{
			ret = false;
			break;
		}
	}

	return canWin[num] = ret;
}

int main()
{
	memset(canWin, -1, sizeof(canWin));
	cin >> n >> k;
	cin.ignore();
	string line;
	getline(cin, line);
	line += " ";
	string delimiter = " ";

	int curPos = 0;
	int pos;
	while ((pos = line.find(delimiter, curPos)) != string::npos)
	{
		int len = pos - curPos;
		string num = line.substr(curPos, len);
		cantUse[stoi(num)] = true;
		canWin[stoi(num)] = false;
		curPos = pos + 1;
	}

	for (int i = 1; i <= k; ++i)
	{
		if (Recur(i, true))
		{
			cout << 1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
