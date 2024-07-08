#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int inputArr[20000][5];
pair<int, int> arr[5][20000];
vector<int> vec;
bool selected[25];
int res;

void Recur(int level, int total)
{
	if (5 == level)
	{
		res = max(res, total);
		return;
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		if (selected[i]) continue;
		selected[i] = true;
		Recur(level + 1, total + inputArr[vec[i]][level]);
		selected[i] = false;
	}
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> inputArr[i][j];
			arr[j][i].first = inputArr[i][j];
			arr[j][i].second = i;
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		sort(arr[i], arr[i] + n);
		for (int j = n - 1; j > n - 6; --j)
		{
			vec.push_back(arr[i][j].second);
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	Recur(0, 0);
	cout << res << endl;
}