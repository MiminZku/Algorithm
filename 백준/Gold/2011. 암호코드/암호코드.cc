#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

string str;
int n;
int ans;
int memo[5005];

int BackTracking(int idx)
{
	if (idx >= n)
	{
		return 1;
	}

	if (memo[idx] != -1)
	{
		return memo[idx];
	}
	
	int ret = 0;

	string temp;
	temp.push_back(str[idx]);

	int num = stoi(temp);
	if (num == 0)
	{
		return 0;
	}

	ret += BackTracking(idx + 1);	
	if (idx + 1 < n)
	{
		temp.push_back(str[idx + 1]);
		num = stoi(temp);

		if (num <= 26)
		{
			ret += BackTracking(idx + 2);
		}
	}

	return memo[idx] = ret % 1000000;
}

int main()
{
	memset(memo, -1, sizeof(memo));

	cin >> str;
	n = str.size();	

	cout << BackTracking(0) << endl;
}