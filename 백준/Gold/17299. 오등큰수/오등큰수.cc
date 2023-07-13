#include <iostream>
#include <stack>

#define INF 2147483647

using namespace std;

int n;
int cnt[1000001];

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    int input[n+1];
    for(int i=1; i<=n; i++){
        cin>>input[i];
        cnt[input[i]]++;
    }
    int org_input[n+1];
    for(int i=1; i<=n; i++){
        org_input[i] = input[i];
        input[i] = cnt[input[i]];
    }

    int result[n+1];

    stack<pair<int,int>> st;    // 빌딩의 높이, 위치
    st.push({INF,n+1});

    for(int i=n,k; i>0; i--){
        k = input[i];
        if(st.top().first <= k){
            while(st.top().first <= k){
                st.pop();
            }
        }
        result[i] = st.top().second;
        st.push({k,i});
    }
    for(int i=1; i<=n; i++){
        if(result[i] == n+1)    cout<<"-1 ";
        else    cout<<org_input[result[i]]<<' ';
    }
    cout<<'\n';
}