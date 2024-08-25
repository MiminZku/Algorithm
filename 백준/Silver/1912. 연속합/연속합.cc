#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> memo[2];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    arr.resize(n);
    memo[0].resize(n);
    memo[1].resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    memo[0][0] = arr[0];
    memo[1][0] = arr[0];
    for(int i=1; i<n; i++)
    {
        memo[0][i] = max(memo[0][i-1], memo[1][i-1]);
        memo[1][i] = max(arr[i], memo[1][i-1] + arr[i]);
    }

    int result = max(memo[0][n-1], memo[1][n-1]);
    cout<<result<<endl;
}