#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[15000];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int ans = 0;
    int l = 0, r = n-1;
    while(l < r)
    {
        int sum = arr[l] + arr[r];
        if(sum == m)
        {
            ++ans;
            ++l;
            --r;
        }
        else if(sum > m)
        {
            --r;
        }
        else
        {
            ++l;
        }
    }

    cout<<ans<<endl;
}