#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string str;
pair<int, int> pairIdx[10];
set<string> ans;
int pNum;
bool selected[10];

void Recur(int level)
{
	if (level == pNum)
	{
		string tmp = "";
		bool erased[200] = {};
		for (int i = 0; i < pNum; ++i)
		{
			if (selected[i])
			{
				erased[pairIdx[i].first] = true;
				erased[pairIdx[i].second] = true;
			}
		}

		for (int i = 0; i < str.size(); ++i)
		{
			if (erased[i])	continue;
			tmp.push_back(str[i]);
		}

		ans.insert(tmp);

		return;
	}

	selected[level] = true;
	Recur(level + 1);
	selected[level] = false;
	Recur(level + 1);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> str;
	vector<int> stack;
	for (int i = 0, cnt = 0; i < str.size(); ++i)
	{
		char ch = str[i];
		if (ch == '(')
		{
			stack.push_back(i);
		}
		else if (ch == ')')
		{
			pairIdx[cnt++] = make_pair(i, stack.back());
			stack.pop_back();
			pNum = cnt;
		}
	}

	Recur(0);

	for (auto i = ++ans.begin(); i != ans.end(); ++i)
	{
		cout << *i << '\n';
	}
}