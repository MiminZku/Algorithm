#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    sort(arr, arr + n);

    int ans = 0;
    for(int i=0; i<n; ++i)
    {
        ans = max(ans, (n-i)*arr[i]);
    }
    cout<<ans<<endl;
}