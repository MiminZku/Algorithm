#include <iostream>

#define fastio cin.tie(nullptr), ios::sync_with_stdio(false);
#define INF 2147483647;

using namespace std;

int fileSize[501][501];

void Solve(int dp[][501], int k){
    for(int i=k; i>0; i--){
        for(int j=i; j<=k; j++){
            if(i==j)    continue;
            
            int minCost = INF; int minSize = INF;
            for(int p=0; p<j-i; p++){
                int newFileSize = fileSize[i][i+p] + fileSize[i+p+1][j];
                int temp = dp[i][i+p] + dp[i+p+1][j] + newFileSize;
                if (temp <= minCost){
                    minCost = temp;
                    if(newFileSize < minSize)
                        minSize = newFileSize;
                }
            }
            dp[i][j] = minCost;
            fileSize[i][j] = minSize;
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int k;
        cin>>k;
        int dp[501][501];
        for(int j=1; j<k+1; j++){
            int n;
            cin>>n;
            fileSize[j][j] = n;
            dp[j][j] = 0;
        }
        Solve(dp,k);
        cout<<dp[1][k]<<'\n';
    }
}