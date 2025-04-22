#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int sensorPos[10000];
int interSensor[9999];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> sensorPos[i];
	}

	sort(sensorPos, sensorPos + n);

	for (int i = 1; i < n; ++i)
	{
		interSensor[i - 1] = sensorPos[i] - sensorPos[i - 1];
	}

	sort(interSensor, interSensor + (n - 1));

	int ans = 0;
	for (int i = 0; i < n - k; ++i)
	{
		ans += interSensor[i];
	}

	cout << ans << endl;
}