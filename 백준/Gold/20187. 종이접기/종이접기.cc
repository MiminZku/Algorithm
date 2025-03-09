#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector<char> fold;
int hole;

void UnfoldUp(vector<vector<int>>& org)
{
	int rowNum = org.size();
	for (int i = 0; i < rowNum; ++i)
	{
		org.push_back(org[i]);
	}
	for (int i = 0; i < rowNum; ++i)
	{
		for (int j = 0; j < org[i].size(); ++j)
		{
			org[i][j] = (org[org.size() - 1 - i][j] + 2) % 4;
		}
	}
}

void UnfoldDown(vector<vector<int>>& org)
{
	int rowNum = org.size();
	for (int i = 0; i < rowNum; ++i)
	{
		org.push_back(vector<int>(org[i].size()));
	}
	for (int i = 0; i < rowNum; ++i)
	{
		for (int j = 0; j < org[i].size(); ++j)
		{
			org[rowNum + i][j] = (org[rowNum - 1 - i][j] + 2) % 4;
		}
	}
}

void UnfoldLeft(vector<vector<int>>& org)
{
	int colNum = org[0].size();
	for (int i = 0; i < org.size(); ++i)
	{
		for (int j = 0; j < colNum; ++j)
		{
			org[i].push_back(org[i][j]);
		}
		for (int j = 0; j < colNum; ++j)
		{
			int val = -1;
			int tmp = org[i][org[i].size() - 1 - j];
			if (tmp == 0)		val = 1;
			else if (tmp == 1)	val = 0;
			else if (tmp == 2)	val = 3;
			else if (tmp == 3)	val = 2;

			org[i][j] = val;
		}
	}	
}

void UnfoldRight(vector<vector<int>>& org)
{
	int colNum = org[0].size();
	for (int i = 0; i < org.size(); ++i)
	{
		for (int j = 0; j < colNum; ++j)
		{
			int val = -1;
			int tmp = org[i][colNum - 1 - j];
			if (tmp == 0)		val = 1;
			else if (tmp == 1)	val = 0;
			else if (tmp == 2)	val = 3;
			else if (tmp == 3)	val = 2;

			org[i].push_back(val);
		}
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> k;
	cin.ignore();
	fold.resize(2 * k);
	for (int i = 0; i < 2 * k; ++i)
	{
		cin >> fold[i];
	}
	cin >> hole;

	vector<vector<int>> answer(1, vector<int>(1, hole));

	reverse(fold.begin(), fold.end());
	for (char ch : fold)
	{
		if (ch == 'D')
		{
			UnfoldUp(answer);
		}
		else if (ch == 'U')
		{
			UnfoldDown(answer);
		}
		else if (ch == 'R')
		{
			UnfoldLeft(answer);
		}
		else if (ch == 'L')
		{
			UnfoldRight(answer);
		}
	}

	for (const vector<int> vec : answer)
	{
		for (int i : vec)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}