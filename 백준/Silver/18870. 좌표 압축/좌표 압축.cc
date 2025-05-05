#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> sortedArr;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	arr.resize(n);
	sortedArr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sortedArr[i] = arr[i];
	}

	sort(sortedArr.begin(), sortedArr.end());
	sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());

	for (int i : arr)
	{
		cout << (lower_bound(sortedArr.begin(), sortedArr.end(), i) - sortedArr.begin()) << ' ';
	}
	cout << endl;	
}