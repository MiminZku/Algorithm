#include <iostream>

using namespace std;

using ll = long long;
const ll MOD = 10'0000'0007;

ll GCD(ll a, ll b)
{
    if (b == 0)  return a;
    return GCD(b, a % b);
}

ll Mul(ll n, ll m)
{
    if (m == 0)    return 1;
    if (m % 2)  return n * Mul(n, m - 1) % MOD;

    ll ret = Mul(n, m / 2);
    return ret * ret % MOD;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int m;
    cin >> m;
    
    ll a, b;
    ll ans = 0;
    while (m--)
    {
        cin >> b >> a;
        ll gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        ans += a * Mul(b, MOD - 2);
        ans %= MOD;
    }

    cout << ans << endl;
}