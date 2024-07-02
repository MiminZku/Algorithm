#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int arr[100000];
int sortedArr[100000];
bool visited[100000];
unordered_map<int, int> idxOf;
int cnt;

int DFS(int idx, const int firstIdx, int level)
{
	visited[idx] = true;
	if (visited[idxOf[arr[idx]]] && firstIdx == idxOf[arr[idx]])
	{
		return level + 1;
	}
	return DFS(idxOf[arr[idx]], firstIdx, level + 1);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sortedArr[i] = arr[i];
	}
	sort(sortedArr, sortedArr + n);
	for (int i = 0; i < n; ++i)
	{
		idxOf[sortedArr[i]] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])	continue;
		cnt += DFS(i, i, 0) - 1;
	}

	cout << cnt << endl;
}