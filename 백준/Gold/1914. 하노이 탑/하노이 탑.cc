#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr;

void Hanoi(int cur, int temp, int next, int level)
{
	if (level == 0)	return;
	Hanoi(cur, next, temp, level - 1);
	arr.push_back({ cur, next });
	Hanoi(temp, cur, next, level - 1);
}

int main()
{
	cin >> n;

	string ans = to_string(pow(2, n));
	ans = ans.substr(0, ans.find('.'));
	ans.back() -= 1;
	cout << ans << endl;

	if (n <= 20)
	{
		Hanoi(1, 2, 3, n);
		for (const auto& p : arr)
		{
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}