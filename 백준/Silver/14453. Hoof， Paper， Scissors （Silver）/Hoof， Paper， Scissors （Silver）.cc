#include <iostream>

using namespace std;

int n;
int hSum[100001];
int pSum[100001];
int sSum[100001];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; ++i)
	{
		char ch;
		cin >> ch;
		
		hSum[i] = hSum[i - 1] + (ch == 'H');
		pSum[i] = pSum[i - 1] + (ch == 'P');
		sSum[i] = sSum[i - 1] + (ch == 'S');
	}

	int ans = max(max(hSum[n], pSum[n]), sSum[n]);	// 한번도 안바꿨을 때
	for (int i = 1; i <= n; ++i)
	{
		int tmp1 = max(hSum[i] + pSum[n] - pSum[i], hSum[i] + sSum[n] - sSum[i]);
		int tmp2 = max(pSum[i] + hSum[n] - hSum[i], pSum[i] + sSum[n] - sSum[i]);
		int tmp3 = max(sSum[i] + pSum[n] - pSum[i], sSum[i] + hSum[n] - hSum[i]);
		ans = max(ans, max(max(tmp1, tmp2), tmp3));
	}
	cout << ans << endl;
}