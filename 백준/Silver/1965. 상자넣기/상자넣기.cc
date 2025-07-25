#include <iostream>

using namespace std;

int n;
int arr[1000];
int memo[1000];

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

    memo[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        memo[i] = 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                memo[i] = max(memo[i], 1 + memo[j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, memo[i]);
    }

    cout << ans << endl;
}