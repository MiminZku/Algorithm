#include <iostream>
#include <set>

using namespace std;

int n;
set<int> isExist;
int arr[1000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		isExist.insert(arr[i]);
	}

	int res = 1;
	for (auto iter = isExist.begin(); iter != isExist.end(); ++iter)
	{
		int pre = arr[0];
		int len = 1;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i] == *iter)	continue;

			if (pre == arr[i])
			{
				++len;
				res = max(res, len);
			}
			else
			{
				len = 1;
				pre = arr[i];
			}
		}
	}
	cout<<res<<endl;
}