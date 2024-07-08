#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> navers[101];
int dist[101][101];


void BFS(int start){
    bool visited[101] = {};
    visited[start] = true;
    queue<pair<int,int>> q;
    q.push({0,start});

    while(!q.empty()){
        int d = q.front().first;
        int cur = q.front().second;
        q.pop();
        dist[start][cur] = d;
        for(int naver: navers[cur]){
            if(visited[naver])  continue;
            visited[naver] = true;
            q.push({d+1, naver});
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        navers[a].push_back(b);
        navers[b].push_back(a);
    }

    int min = 10000; int res;
    for(int i=1; i<=n; i++){
        BFS(i);
        int sum = 0;
        for(int j=1; j<=n; j++){
            sum+=dist[i][j];
        }
        if(min>sum){
            min = sum;
            res = i;
        };
    }
    cout<<res<<endl;
}