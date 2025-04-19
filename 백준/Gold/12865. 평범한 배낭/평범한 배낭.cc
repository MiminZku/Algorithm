#include <iostream>
#include <memory.h>

using namespace std;

int n, k;
pair<int, int> arr[100000];
int memo[100][100001];

int Recur(int idx, int weight)  
{
    if(weight > k)
    {
        return -2147483648;
    }
    if(idx == n)
    {
        return 0;
    }

    if(memo[idx][weight] != -1)
    {
        return memo[idx][weight];
    }

    return memo[idx][weight] = 
        max(
            Recur(idx + 1, weight),
            Recur(idx + 1, weight + arr[idx].first) + arr[idx].second);
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    cout << Recur(0, 0) << endl;
}