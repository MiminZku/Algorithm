#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500000];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio;

    cin>>n;
    for(int i=0; i<n; ++i)  cin>>arr[i];
    sort(arr, arr+n);

    long long sum = 0;
    for(int i = 1; i < n; ++i)
    {
        sum += arr[i] - arr[0];
    }

    long long ans = sum;
    for(int i=1; i<n; ++i)
    {
        long long delta = arr[i] - arr[i-1];
        sum += (delta * i) - (delta * (n - i));
        ans += sum;
    }
    cout<<ans<<endl;
}