#include <iostream>

using namespace std;

int n, m;
int height[100002];
int arr[100002];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> height[i];
	}

	int a, b, k;
	while (m--)
	{
		cin >> a >> b >> k;
		arr[a] += k;
		arr[b + 1] += -k;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[i] += arr[i - 1];
		cout << height[i] + arr[i] << ' ';
	}
	cout << endl;
}