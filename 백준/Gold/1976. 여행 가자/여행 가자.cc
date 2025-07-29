#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> linkedCities[201];
int plan[1000];
bool visited[201];

void DFS(int city)
{
	visited[city] = true;
	for (int c : linkedCities[city])
	{
		if (visited[c])	continue;
		DFS(c);
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1, k; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> k;
			if (1 == k)
			{
				linkedCities[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> plan[i];
	}

	DFS(plan[0]);

	bool check = true;
	for (int i = 1; i < m; ++i)
	{
		if (false == visited[plan[i]])
		{
			check = false;
			break;
		}
	}

	cout << (check ? "YES\n" : "NO\n");
}