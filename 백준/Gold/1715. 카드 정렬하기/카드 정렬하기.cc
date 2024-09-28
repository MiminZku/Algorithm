#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;
int ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		pq.push(-k);
	}

	while (true)
	{
		int a = -pq.top(); pq.pop();
		if (pq.empty())
		{
			break;
		}
		int b = -pq.top(); pq.pop();

		ans += a + b;
		pq.push(-(a + b));
	}

	cout << ans << endl;
}