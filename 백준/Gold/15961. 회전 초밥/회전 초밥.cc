#include <iostream>
#include <map>

using namespace std;

int n, d, k, c;
int belt[3000000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; ++i)
	{
		cin >> belt[i];
	}

	map<int, int> sushiCnt;
	sushiCnt[c] = 3333333;
	for (int i = 0; i < k; ++i)
	{
		sushiCnt[belt[i]]++;
	}

	int ans = sushiCnt.size();

	for (int i = 1; i < n; ++i)
	{
		int erasedSushi = belt[i - 1];
		int insertedSushi = belt[(i + k - 1) % n];

		sushiCnt[erasedSushi]--;
		if (sushiCnt[erasedSushi] == 0)
		{
			sushiCnt.erase(erasedSushi);
		}
		sushiCnt[insertedSushi]++;

		ans = max(ans, int(sushiCnt.size()));
	}

	cout << ans << endl;
}