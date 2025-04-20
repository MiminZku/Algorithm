#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int n, m;
pair<int, int> arrA[100];
pair<int, int> arrB[100];
vector<int> ans;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
	{
		return a.first > b.first;
	}
	
	return a.second < b.second;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arrA[i].first;
		arrA[i].second = i;
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> arrB[i].first;
		arrB[i].second = i;
	}

	sort(arrA, arrA + n, compare);
	sort(arrB, arrB + m, compare);
	int aPrevIdx = -1, bPrevIdx = -1;
	int a = 0, b = 0;
	while (a < n && b < m)
	{
		int aValue = arrA[a].first;
		int bValue = arrB[b].first;

		if (aValue > bValue)
		{
			a++;
		}
		else if (aValue < bValue)
		{
			b++;
		}
		else
		{
			if (ans.size() == 0 ||
				arrA[a].second > aPrevIdx && arrB[b].second > bPrevIdx)
			{
				aPrevIdx = arrA[a].second;
				bPrevIdx = arrB[b].second;
				ans.push_back(aValue);
				a++;
				b++;
			}
			else
			{
				if (arrA[a].second < aPrevIdx)
				{
					a++;
				}
				else
				{
					b++;
				}
			}
		}
	}

    cout << ans.size() << endl;
	if (ans.size() != 0)
	{
		for (int i : ans)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
}