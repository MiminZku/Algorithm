#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int triangle[500][500];
int dp[500][500];
int n;

int Recur(int level, int col)
{
    if(level == n - 1) return triangle[level][col];
    
    if(dp[level][col] != -1) return dp[level][col];
    
    int temp = 0;
    for(int i=col; i <= col + 1; ++i)
    {
        temp = max(temp, Recur(level + 1, i));
    }    
    return dp[level][col] = temp + triangle[level][col];
}

int main() 
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            cin>>triangle[i][j];
        }
    }
    cout<< Recur(0, 0) << endl;
}