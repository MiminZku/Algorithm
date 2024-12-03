#include <iostream>

using namespace std;

int n;
int arr[120];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;

    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    int ans = arr[0];
    for(int i=1; i<n; ++i)
    {
        ans += 8;
        ans += arr[i];
    }
    cout << ans / 24 << ' ' << ans % 24 << endl;
}