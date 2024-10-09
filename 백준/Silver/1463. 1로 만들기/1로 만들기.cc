#include <iostream>
#include <memory.h>

using namespace std;

int n;
int dp[1000001];

int Recur(int cur)  // cur 숫자가 1이 될때까지 연산을 하는 횟수의 최솟값
{
    if(cur == 1) return 0;
    if(cur < 1) return 2147483647;

    if(dp[cur] != -1)   return dp[cur];

    int temp = 2147483647;
    // 1. x가 3으로 나눠떨어지면 3으로 나눈다
    if(cur % 3 == 0)
    {
        temp = min(temp, Recur(cur / 3) + 1) ;
    }

    // 2. x가 2로 나눠떨어지면 2로 나눔
    if(cur % 2 == 0)
    {
        temp = min(temp, Recur(cur / 2) + 1);
    }

    // 3. 1을 뺌
    temp = min(temp, Recur(cur - 1) + 1);

    return dp[cur] = temp;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    memset(dp, -1, sizeof(dp));

    cout<<Recur(n)<<endl;
}