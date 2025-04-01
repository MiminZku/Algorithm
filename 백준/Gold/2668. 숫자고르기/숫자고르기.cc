#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n;
int arr[101];
bool visited[101];
bool isCycle[101];
int cnt;


bool DFS(int idx, const int firstIdx, vector<int>& visitedArr)
{
	visited[idx] = true;
	visitedArr.push_back(idx);
	if (visited[arr[idx]])
	{
		if (firstIdx == arr[idx])	return true;
		else return false;
	}
	return DFS(arr[idx], firstIdx, visitedArr);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i)
	{
		if (isCycle[i])	continue;
		memset(visited, 0, sizeof(visited));
		vector<int> vec;
		if (DFS(i, i, vec))
		{
			cnt += vec.size();
			for (int i : vec)
			{
				isCycle[i] = true;
			}
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; ++i)
	{
		if (!isCycle[i])	continue;
		cout << i << '\n';
	}
}