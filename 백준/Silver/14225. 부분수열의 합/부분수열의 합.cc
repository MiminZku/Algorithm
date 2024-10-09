#include <iostream>

using namespace std;

int n;
int arr[20];
bool check[2000000];

void Recur(int idx, int total)
{
	if (idx == n)
	{
		check[total] = true;
		return;
	}

	Recur(idx + 1, total + arr[idx]);

	Recur(idx + 1, total);
	
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	Recur(0, 0);

	for (int i = 1; ; ++i)
	{
		if (false == check[i])
		{
			cout << i << endl;
			break;
		}
	}
}