#include <iostream>

using namespace std;

int arr[10];
int ans;

void Recur(int num, int prev, int con, int total)
{
	if (num == 10)
	{
		if (total >= 5) ++ans;
		return;
	}

	for (int i = 1; i <= 5; ++i)
	{
		if (2 == con && i == prev)	continue;
		
		Recur(num + 1, i, (prev == i) ? con + 1 : 1, total + (arr[num] == i));
	}
}


int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	for (int i = 0; i < 10; ++i)
	{
		cin >> arr[i];
	}

	Recur(0, 0, 0, 0);

	cout << ans << endl;
}