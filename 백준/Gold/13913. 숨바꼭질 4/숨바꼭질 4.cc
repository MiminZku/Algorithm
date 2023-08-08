#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;

    queue<pair<int,int>> q;
    q.push({n,0});

    int parent[200000];
    fill_n(parent, 200000, -1);
    vector<int> path;
    bool visited[200001] = {};
    visited[n] = true;
    
    while(!q.empty()){
        int curPos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(curPos == k){
            cout<<time<<endl;
            while(curPos>=0){
                path.push_back(curPos);
                curPos = parent[curPos];
            }
            break;
        }

        int nextPos[3] = {curPos-1, curPos+1, 2*curPos};
        for(int i=0; i<3; i++){
            if(nextPos[i] > 200000 || nextPos[i]<0)  continue;
            if(visited[nextPos[i]]) continue;
            visited[nextPos[i]] = true;
            parent[nextPos[i]] = curPos;
            q.push({nextPos[i], time+1});
        }
    }
    for(int i=path.size()-1; i>=0; i--)
        cout<<path[i]<<' ';
    cout<<endl;
}