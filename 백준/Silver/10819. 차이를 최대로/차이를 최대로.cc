#include <iostream>

using namespace std;

int n;
int arr[8];
int path[8];
int visited[8];
int res;

void Recur(int level)
{
	if (level == n)
	{
		int sum = 0;
		for (int i = 1; i < n; ++i)
		{
			sum += abs(path[i] - path[i - 1]);
		}

		res = max(res, sum);

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])	continue;
		visited[i] = true;
		path[level] = arr[i];
		Recur(level + 1);
		visited[i] = false;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	Recur(0);

	cout << res << endl;
}