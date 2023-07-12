#include <iostream>

using namespace std;


int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1][3] = {};
        for(int i=1; i<=2; i++){
            for(int j=1; j<=n; j++){
                cin>>arr[j][i];
            }
        }

        // memo[i][j] => 0~i 열까지의 최대값(i열에서는 j행 스티커 선택)
        int memo[n+1][3] = {};  
        for(int i=1; i<=n; i++){
            memo[i][0] = max(memo[i-1][1], memo[i-1][2]);

            memo[i][1] = max(memo[i-1][0], memo[i-1][2]) + arr[i][1];

            memo[i][2] = max(memo[i-1][0], memo[i-1][1]) + arr[i][2];
        }
        int res=0;
        for(int i=0; i<3; i++){
            if(res < memo[n][i])    res = memo[n][i];
        }
        cout<<res<<'\n';
    }    
}