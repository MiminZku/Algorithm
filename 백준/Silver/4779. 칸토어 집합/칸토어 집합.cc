#include <iostream>

using namespace std;

void Recur(string& str, int s, int e)
{
	int len = e - s + 1;
	if(len <= 1)	return;

	int t1 = s + len / 3;
	int t2 = t1 + len / 3;

	for(int i=t1; i<t2; ++i)
	{
		str[i] = ' ';
	}

	Recur(str, s, t1 - 1);
	Recur(str, t2, e);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	int n;
	while(cin >> n)
	{
		int k = 1;
		for(int i=0; i<n; ++i)
		{
			k *= 3;
		}
		string str = "";
		for(int i=0; i<k; ++i)
		{
			str.push_back('-');
		}

		Recur(str, 0, k - 1);

		cout << str << '\n';
	}
}