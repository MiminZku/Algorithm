#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    int x;
    cin>>x;

    int arr[n];
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }
    int res = arr[0] + arr[1];
    for(int i=2; i<n; ++i)
    {
        int sum = arr[i] + arr[i-1];
        if(sum < res)
        {
            res = sum;
        }    
    }
    cout<<res*x<<endl;
}