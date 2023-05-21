#include <iostream>
#include <vector>

using namespace std;

int n;
int populations[10001];    // populations[i] : i번 마을의 주민 수
vector<int> navers[10001];    // navers[i] : i번 마을과 인접한 마을들의 리스트
int dp[2][10001];

int DP(int selected, int townNum, int parent){
    if(dp[selected][townNum]>=0)  return dp[selected][townNum];
    else{
        int result = 0;
        if(selected){
            result = populations[townNum]; 
            for(int naver: navers[townNum]){
                if(naver==parent)   continue;
                result += DP(0,naver,townNum);
            }
        }
        else{
            for(int naver: navers[townNum]){
                if(naver==parent)   continue;
                result += max(DP(0,naver,townNum),DP(1,naver,townNum));
            }
        }
        dp[selected][townNum] = result;
        return result;
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<=n; i++){
        dp[0][i] = -1;
        dp[1][i] = -1;
    }
    for(int i=1; i<=n; i++) cin>>populations[i];
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        navers[a].push_back(b);
        navers[b].push_back(a);
    }

    cout<<max(DP(0,n,0), DP(1,n,0))<<endl;
}