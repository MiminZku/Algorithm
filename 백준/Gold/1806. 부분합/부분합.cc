#include <iostream>

using namespace std;

int n;
int s;
int arr[100001];
int prefixSum[100001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		prefixSum[i] += prefixSum[i - 1] + arr[i];
	}

	int begin = 1;
	int shortestLen = 999999;
	for (int end = 1; end <= n && begin <= end;)
	{
		int sum = prefixSum[end] - prefixSum[begin - 1];
		int len = end - begin + 1;
		if (sum >= s)
		{
			++begin;
			shortestLen = min(shortestLen, len);
		}
		else
		{
			++end;
		}
	}
	
	cout << ((999999 == shortestLen) ? 0 : shortestLen) << endl;
}