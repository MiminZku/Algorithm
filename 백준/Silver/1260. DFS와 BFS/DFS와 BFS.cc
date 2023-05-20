#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<int> edges[], bool visited[], int curNode){
    cout<<curNode<<' ';
    visited[curNode] = true;
    for(int nextNode : edges[curNode]){
        if(visited[nextNode])   continue;
        dfs(edges,visited,nextNode);
    }
}
void bfs(vector<int> edges[], int firstNode){
    bool visited[1001] = {};
    visited[firstNode] = true;
    queue<int> q;
    q.push(firstNode);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<' ';
        for(int nextNode : edges[cur]){
            if(visited[nextNode])   continue;
            visited[nextNode] = true;
            q.push(nextNode);
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,m,v;
    cin>>n>>m>>v;
    vector<int> edges[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=1; i<n+1; i++){
        sort(edges[i].begin(),edges[i].end());
    }
    bool visited[n+1]={};
    dfs(edges, visited, v);
    cout<<endl;
    bfs(edges, v);
    cout<<endl;
}