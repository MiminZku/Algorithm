#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[1000];
int leftMemo[1000][1001];
int rightMemo[1000][1001];

int Left(int curIdx, int prevValue) // curIdx 를 기준으로 왼쪽으로 계속 작아지는 부분 수열의 최대 길이
{
	if (curIdx < 0) return 0;

	if (leftMemo[curIdx][prevValue] != -1) return leftMemo[curIdx][prevValue];

	int ret = 0;
	if (arr[curIdx] < prevValue)
	{
		ret = max(ret, 1 + Left(curIdx - 1, arr[curIdx]));
	}
	ret = max(ret, Left(curIdx - 1, prevValue));

	return leftMemo[curIdx][prevValue] = ret;
}

int Right(int curIdx, int prevValue) // curIdx 를 기준으로 오른쪽으로 계속 작아지는 부분 수열의 최대 길이
{
	if (curIdx >= n) return 0;

	if (rightMemo[curIdx][prevValue] != -1) return rightMemo[curIdx][prevValue];

	int ret = 0;
	if (arr[curIdx] < prevValue)
	{
		ret = max(ret, 1 + Right(curIdx + 1, arr[curIdx]));
	}
	ret = max(ret, Right(curIdx + 1, prevValue));

	return rightMemo[curIdx][prevValue] = ret;
}


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(leftMemo, -1, sizeof(leftMemo));
	memset(rightMemo, -1, sizeof(rightMemo));
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, 1 + Left(i, arr[i]) + Right(i, arr[i]));
	}

	cout << ans << endl;
}