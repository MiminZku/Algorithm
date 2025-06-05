#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	vector<string> strArr;
	cin >> n;
	cin.ignore();
	strArr.resize(n);
	vector<pair<char, int>> alphabets;
	for (int i = 0; i < n; ++i)
	{
		cin >> strArr[i];
		for (int j = 0; j < strArr[i].size(); ++j)
		{
			alphabets.push_back({ strArr[i][j], strArr[i].size() - 1 - j });
		}
	}

	vector<int> a2n(26, 0);
	for (const auto& p : alphabets)
	{
		a2n[p.first - 'A'] += pow(10, p.second);
	}

	sort(a2n.begin(), a2n.end(), greater<int>());

	int ans = 0;
	int num = 9;
	for (int i = 0; i < 10; ++i)
	{
		ans += a2n[i] * num--;
	}
	cout << ans << endl;
}