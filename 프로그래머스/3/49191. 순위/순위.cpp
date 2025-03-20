#include <vector>
#include <queue>

using namespace std;

vector<int> leftPlayers[101];
vector<int> rightPlayers[101];
int ranking[101][2];

int solution(int n, vector<vector<int>> results) {
    
	for (const auto& res : results)
	{
		rightPlayers[res[0]].push_back(res[1]);
		leftPlayers[res[1]].push_back(res[0]);
	}

	for (int i = 1; i <= n; ++i)
	{
		queue<int> q;
		bool visited[101] = {};
		q.push(i);
		visited[i] = true;
		int cnt = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			cnt++;

			for (int p : leftPlayers[cur])
			{
				if (visited[p])	continue;
				visited[p] = true;
				q.push(p);
			}
		}
		ranking[i][0] = cnt;
	}

	for (int i = 1; i <= n; ++i)
	{
		queue<int> q;
		bool visited[101] = {};
		q.push(i);
		visited[i] = true;
		int cnt = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			cnt++;

			for (int p : rightPlayers[cur])
			{
				if (visited[p])	continue;
				visited[p] = true;
				q.push(p);
			}
		}
		ranking[i][1] = n - cnt + 1;
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (ranking[i][0] == ranking[i][1])
		{
			ret++;
		}
	}

	return ret;

    
}