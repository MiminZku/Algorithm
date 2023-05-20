#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seq=1;

void dfs(vector<int> edges[], int visited[], int curNode){
    visited[curNode] = seq++;
    for(int nextNode : edges[curNode]){
        if(visited[nextNode])   continue;
        dfs(edges,visited,nextNode);
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,m,r;
    cin>>n>>m>>r;
    vector<int> edges[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=1; i<n+1; i++){
        sort(edges[i].begin(),edges[i].end(),greater<int>());
    }
    int visited[n+1]={};
    dfs(edges,visited,r);
    for(int i=1; i<n+1; i++){
        cout<<visited[i]<<'\n';
    }
}