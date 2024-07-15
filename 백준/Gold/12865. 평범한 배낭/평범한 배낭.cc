#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, k;
pair<int, int> arr[100];
int ans;
int dp[100][100001];

int Recur(int cur, int weight) // cur번째 까지 왔는데 무게가 weight 만큼 찼을 때 최대 가치 반환
{
	if(weight > k)	return -2147483647;
	if (cur == n)	return 0;

	if (dp[cur][weight] != -1)	return dp[cur][weight];

	// cur번 째 물건을 선택할 경우
	int temp = Recur(cur + 1, weight + arr[cur].first) + arr[cur].second;

	// 선택 안할 경우
	int temp2 = Recur(cur + 1, weight);

	return dp[cur][weight] = max(temp, temp2);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	
	cout << Recur(0, 0) << endl;
}