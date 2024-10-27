#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n;
pair<int, int> arr[100000];
map<int, int> idxArr;

int LIS()
{
	vector<int> lis;
	vector<pair<int, int>> record;

	for (int i = 0; i < n; ++i) {
		
		int num = arr[i].second;
		
		// 이분 탐색을 통해 lis에서 num의 위치를 찾기
		int idx = lis.size();
		int l = 0, r = lis.size() - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (lis[mid] >= num)
			{
				r = mid - 1;
				idx = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		// num이 lis의 끝보다 크면 추가
		if (idx == lis.size())
		{
			lis.push_back(num);
		}
		// 아니면 해당 위치에 있는 값을 num으로 대체
		else	
		{
			lis[idx] = num;
		}
		record.push_back({ idx, num });
	}

	int lisSize = lis.size();
	lis.clear();

	reverse(record.begin(), record.end());

	int cnt = lisSize - 1;
	for (pair<int, int> p : record)
	{
		if (p.first == cnt)
		{
			lis.push_back(p.second);
			--cnt;
			if (0 > cnt)	break;
		}
	}

	for (int i : lis)
	{
		idxArr[i] = -1;
	}

	return lisSize;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
		idxArr.insert({ arr[i].second, arr[i].first });
	}
	sort(arr, arr + n);

	cout << n - LIS() << endl;

	for (int i = 0; i < n; ++i)
	{
		if (-1 == idxArr[arr[i].second])	continue;
		cout << arr[i].first << '\n';
	}
}
