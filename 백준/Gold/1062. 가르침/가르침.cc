#include <iostream>
#include <vector>

using namespace std;

int n, k;
int knowMask;	// bitmask
vector<int> words;
int ans;

void Recur(int level, int start)
{
	if (level == k)
	{
		int cnt = 0;

		for (int mask : words)
		{
			if ((mask & knowMask) == mask)
			{
				cnt++;
			}
		}

		ans = max(ans, cnt);
		return;
	}

	for (int i = start; i < 26; ++i)
	{
		if (knowMask & (1 << i))	continue;
		knowMask |= (1 << i);
		Recur(level + 1, i + 1);
		knowMask &= ~(1 << i);
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	cin.ignore();
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		int mask = 0;
		for (char ch : str)
		{
			mask |= 1 << (ch - 'a');
		}
		words.push_back(mask);
	}

	if (k < 5)
	{
		cout << "0\n";
		return 0;
	}

	char know[] = { 'a', 'c', 'i', 'n', 't' };
	for (char ch : know)
	{
		knowMask |= 1 << (ch - 'a');
	}

	Recur(5, 0);

	cout << ans << endl;
}