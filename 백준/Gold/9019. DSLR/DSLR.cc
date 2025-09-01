#include <iostream>
#include <queue>

using namespace std;

char i2c[4] = { 'D', 'S', 'L', 'R' };

int a, b;

int DSLR(int cmd, int num) 
{
	if (i2c[cmd] == 'D')
	{
		return (num * 2) % 10000;
	}
	else if (i2c[cmd] == 'S')
	{
		if (num == 0)
		{
			return 9999;
		}
		return num - 1;
	}
	else if (i2c[cmd] == 'L')
	{
		return (num % 1000) * 10 + num / 1000;
	}
	else if (i2c[cmd] == 'R')
	{
		return (num % 10) * 1000 + num / 10;
	}
}

void BFS(vector<char>& ans)
{
	vector<bool> visited(10000, false);
	vector<int> parent(10000, -1);
	vector<char> cmd(10000, -1);

	queue<int> q;
	q.push(a);
	visited[a] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == b)
		{
			while (parent[cur] != -1)
			{
				ans.push_back(cmd[cur]);
				cur = parent[cur];
			}
			reverse(ans.begin(), ans.end());
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int next = DSLR(i, cur);
			if (visited[next]) continue;
			visited[next] = true;
			parent[next] = cur;
			cmd[next] = i2c[i];
			q.push(next);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		vector<char> ans;
		BFS(ans);
		for (char ch : ans)
		{
			cout << ch;
		}
		cout << '\n';
	}
}