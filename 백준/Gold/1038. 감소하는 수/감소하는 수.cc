#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n;
int path[11];
vector<long long> decNum;

void Recur(int level, int prev)
{
	for (int i = prev - 1; i >= 0; --i)
	{
		path[level] = i;
		long long tmp = 0;
		for (int j = 0; j <= level; ++j)
		{
			tmp += path[j] * pow(10, (long long)level - j);
		}
		decNum.push_back(tmp);
		Recur(level + 1, i);
	}
}

int main()
{
	Recur(0, 10);
	sort(decNum.begin(), decNum.end());
	cin >> n;
	if (n >= decNum.size())
	{
		cout << "-1\n";
		return 0;
	}
	cout << decNum[n] << endl;
}