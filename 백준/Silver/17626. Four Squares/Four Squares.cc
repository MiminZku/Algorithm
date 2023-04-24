#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int dp[n+1] = {0};
    for(int i=1; i*i<=n; i++){
        dp[i*i] = 1;
    }
    for(int i=1; i<=n; i++){
        if(dp[i]==1)    continue;
        int min = 50000;
        for(int j=1; j*j<i; j++){
            int temp = dp[i-j*j] + 1;
            if(temp < min)  min = temp;
        }
        dp[i] = min;
    }
    printf("%d\n",dp[n]);
}