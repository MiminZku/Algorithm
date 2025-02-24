#include <iostream>

using namespace std;

int n;
int price[11];
int m;
int ans;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n;
    
    for(int i=1; i<=n; ++i)
    {
        cin >> price[i];
    }

    cin >> m;

    for(int i=0, k; i<m; ++i)
    {
        cin >> k;
        ans += price[k];
    }

    cout << ans << endl;
}