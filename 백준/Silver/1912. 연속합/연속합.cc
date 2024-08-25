#include <iostream>

using namespace std;

int n;
int preSumMax[101010];
int ans = -2147483648;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, num; i <= n; ++i)
    {
        cin >> num;
        preSumMax[i] = max(num, preSumMax[i - 1] + num);
        ans = max(ans, preSumMax[i]);
    }

    cout << ans << endl;
}