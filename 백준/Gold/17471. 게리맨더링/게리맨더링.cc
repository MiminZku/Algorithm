#include <iostream>
#include <queue>

using namespace std;

int n;
int pop[11];
vector<int> navers[11];
int ans = 1'000;
bool selected[11];
bool visited[11];


void BFS(int start)
{
	visited[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto naver : navers[cur])
		{
			if (selected[cur] != selected[naver])	continue;
			if (visited[naver])	continue;
			visited[naver] = true;
			q.push(naver);
		}
	}
}

void Recur(int reg)
{
	if (reg > n)
	{
		for (int i = 1; i <= n; ++i)
		{
			visited[i] = false;
		}

		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == false)
			{
				cnt++;
				BFS(i);
			}
		}

		if (cnt == 2)
		{
			int a = 0, b = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (selected[i])
				{
					a += pop[i];
				}
				else
				{
					b += pop[i];
				}
			}

			ans = min(ans, abs(a - b));
		}
		return;
	}

	selected[reg] = true;
	Recur(reg + 1);
	selected[reg] = false;
	Recur(reg + 1);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> pop[i];
	}
	for (int i = 1, a; i <= n; ++i)
	{
		cin >> a;
		for (int j = 0, b; j < a; ++j)
		{
			cin >> b;
			navers[i].push_back(b);
		}
	}

	Recur(1);

	if (ans >= 1000)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << endl;
	}
}