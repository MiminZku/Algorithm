#include <iostream>

using namespace std;

typedef long long ll;

int n;
int dice[6];

int Dice(char ch)
{
	return dice[ch - 'A'];
}

int main()
{
	cin >> n;
	for (int i = 0; i < 6; ++i)
	{
		cin >> dice[i];
	}

	ll ans = 0;
	if (n == 1)
	{
		int biggest = 0;
		for (int i = 0; i < 6; ++i)
		{
			biggest = max(biggest, dice[i]);
			ans += dice[i];
		}
		cout << (ans - biggest) << endl;
		return 0;
	}

	ll cnt1 = (ll)(n - 2) * (n - 2) + (ll)(n - 2) * (n - 1) * 4;

	int smallest = 50;
	for (int i = 0; i < 6; ++i)
	{
		smallest = min(smallest, dice[i]);
	}

	ll cnt2 = (n - 2) * 4 + (n - 1) * 4;
	int min2 = 100;
	min2 = min(min2, Dice('A') + Dice('B'));
	min2 = min(min2, Dice('A') + Dice('C'));
	min2 = min(min2, Dice('A') + Dice('D'));
	min2 = min(min2, Dice('A') + Dice('E'));
	min2 = min(min2, Dice('B') + Dice('C'));
	min2 = min(min2, Dice('B') + Dice('D'));
	min2 = min(min2, Dice('B') + Dice('F'));
	min2 = min(min2, Dice('C') + Dice('E'));
	min2 = min(min2, Dice('C') + Dice('F'));
	min2 = min(min2, Dice('D') + Dice('E'));
	min2 = min(min2, Dice('D') + Dice('F'));
	min2 = min(min2, Dice('E') + Dice('F'));

	ll cnt3 = 4;
	int min3 = 150;
	min3 = min(min3, Dice('A') + Dice('B') + Dice('C'));
	min3 = min(min3, Dice('A') + Dice('B') + Dice('D'));
	min3 = min(min3, Dice('A') + Dice('C') + Dice('E'));
	min3 = min(min3, Dice('A') + Dice('D') + Dice('E'));
	min3 = min(min3, Dice('B') + Dice('C') + Dice('F'));
	min3 = min(min3, Dice('B') + Dice('D') + Dice('F'));
	min3 = min(min3, Dice('C') + Dice('E') + Dice('F'));
	min3 = min(min3, Dice('D') + Dice('E') + Dice('F'));

	ans = cnt1 * smallest + cnt2 * min2 + cnt3 * min3;
	cout << ans << endl;
}