#include <iostream>

using namespace std;

int n;
int memo[10][1001];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < 10; ++i)
    {
        memo[i][1] = 1;
    }

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 2; j <= n; ++j)
        {
            for(int k = 0; k <= i; ++k)
            {
                memo[i][j] += memo[k][j - 1];
                memo[i][j] %= 10007;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; ++i)
    {
        ans += memo[i][n];
        ans %= 10007;
    }

    cout << ans << endl;
}