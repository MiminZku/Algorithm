#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[1000];
int leftMemo[1000];
int rightMemo[1000];

int Left(int curIdx) // curIdx 를 기준으로 왼쪽으로 계속 작아지는 부분 수열의 최대 길이
{
	if (leftMemo[curIdx] != -1) return leftMemo[curIdx];

	int ret = 1;
	for (int i = curIdx - 1; i >= 0; --i)
	{
		if (arr[i] < arr[curIdx])
		{
			ret = max(ret, 1 + Left(i));
		}
	}

	return leftMemo[curIdx] = ret;
}

int Right(int curIdx) // curIdx 를 기준으로 오른쪽으로 계속 작아지는 부분 수열의 최대 길이
{
	if (rightMemo[curIdx] != -1) return rightMemo[curIdx];

	int ret = 1;
	for (int i = curIdx + 1; i < n; ++i)
	{
		if (arr[i] < arr[curIdx])
		{
			ret = max(ret, 1 + Right(i));
		}
	}

	return rightMemo[curIdx] = ret;
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
		ans = max(ans, Left(i) + Right(i) - 1);
	}

	cout << ans << endl;
}