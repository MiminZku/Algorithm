#include<iostream>

using namespace std;


int n, s;
int arr[20];
int ans;

void Recur(int idx, int total)
{
	if (idx == n)
	{
		if (total == s) ++ans;
		return;
	}

	// 이번 idx 를 뽑을 경우
	Recur(idx + 1, total + arr[idx]);
	
	// 이번거 안뽑을 경우
	Recur(idx + 1, total);
}


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; ++i)cin >> arr[i];

	Recur(0, 0);
	
	cout << ans - ((s == 0) ? 1 : 0) << endl;
}