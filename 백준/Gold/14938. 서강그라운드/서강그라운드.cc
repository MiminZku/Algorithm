#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n,m,r;
int items[101];
vector<pair<int,int>> edges[101];
int res;

int GetItemsFrom(int region){
    int ret = 0;
    int visited[101];
    for(int i=0; i<101; i++)    visited[i] = 9999;
    visited[region] = 0;
    set<int> canVisit;
    canVisit.insert(region);
    queue<pair<int,int>> q;
    q.push({region, 0});
    while(!q.empty()){ 
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        canVisit.insert(cur);

        for(int i=0; i<edges[cur].size(); i++){
            int naver = edges[cur][i].first;
            int d = edges[cur][i].second;
            if(dist + d > m)    continue;
            if(visited[naver] <= dist + d)  continue;
            visited[naver] = dist+d;
            q.push({naver,dist+d});
        }
    }
    for(int i : canVisit)   ret+=items[i];
    return ret;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m>>r;
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        items[i] = k;
    }
    while(r--){
        int a,b,l;
        cin>>a>>b>>l;
        edges[a].push_back({b,l});
        edges[b].push_back({a,l});
    }

    for(int i=1; i<=n; i++){
        int itemNum = GetItemsFrom(i);
        res = max(res, itemNum);
    }
    cout<<res<<endl;
}