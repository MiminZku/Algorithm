#include <iostream>
#include <memory.h>

using namespace std;

int n, s;
string scroll;
string bridge[2];
int dp[100][20][2];

int Recur(int idx, int cnt, bool isAngel)
{
    if (cnt == s)
    {
        return 1;
    }
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][cnt][isAngel] != -1) return dp[idx][cnt][isAngel];

    int tmp = 0;
    for (int i = idx + 1; i < n; ++i)
    {
        if (bridge[isAngel][i] == scroll[cnt])
        {
            tmp += Recur(i, cnt + 1, !isAngel);
        }
    }

    return dp[idx][cnt][isAngel] = tmp;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin.tie(nullptr); ios::sync_with_stdio(false);   
    cin >> scroll >> bridge[0] >> bridge[1];
    s = scroll.length();
    n = bridge[0].length();

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (bridge[0][i] == scroll[0])
        {
            ans += Recur(i, 1, true);
        }
        if (bridge[1][i] == scroll[0])
        {
            ans += Recur(i, 1, false);
        }
    }

    cout << ans << endl;
}