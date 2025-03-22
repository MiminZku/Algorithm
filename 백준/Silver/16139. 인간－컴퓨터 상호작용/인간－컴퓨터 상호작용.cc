#include <iostream>

using namespace std;

int preSum[26][200000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	string str;
	cin >> str;

	preSum[str[0] - 'a'][0] = 1;
	for (int i = 1; i < str.length(); ++i)
	{
		preSum[str[i] - 'a'][i] = 1;
		for (int j = 0; j < 26; ++j)
		{
			preSum[j][i] += preSum[j][i - 1];
		}
	}

	int q;
	cin >> q;
	char a;
	int l, r;
	while (q--)
	{
		cin.ignore();
		cin >> a;
		cin.ignore();
		cin >> l >> r;

		if (l == 0)
		{
			cout << preSum[a - 'a'][r] << '\n';
		}
		else
		{
			cout << preSum[a - 'a'][r] - preSum[a - 'a'][l - 1] << '\n';
		}
	}
}