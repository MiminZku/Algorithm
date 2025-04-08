#include <iostream>
#include <queue>

using namespace std;

int n, m;
int student[32001][2];
vector<int> nexts[32001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> m;
	int a, b;
	while (m--)
	{
		cin >> a >> b;
		student[a][1]++;
		student[b][0]++;
		nexts[a].push_back(b);
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (student[i][0] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int i : nexts[cur])
		{
			student[i][0]--;
			if (student[i][0] == 0)
			{
				q.push(i);
			}
		}
	}
	cout << endl;
}