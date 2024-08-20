#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> vec;
long long ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> k;
	vec.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	int s = 0, e = n - 1, prev = 0;
	for (int i = 0; i < k; ++i)
	{
		int cur = (i % 2) ? vec[s++] : vec[e--];
		if (prev < cur)
			ans += cur - prev;
		prev = cur;
	}

	cout << ans << endl;
}