#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    queue<pair<int,int>> q;
    q.push({n,0});

    bool visited[200001] = {};
    visited[n] = true;

    while(!q.empty()){
        int curPos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(curPos == k){
            cout<<time<<endl;
            return 0;
        }

        if(curPos != 0 && 2*curPos <= 200000 && !visited[2*curPos]){
            visited[2*curPos] = true;
            q.push({2*curPos, time});
            q.push({curPos,time});
            continue;
        }
        int nextPos[2] = {curPos-1, curPos+1};
        for(int i=0; i<2; i++){
            if(nextPos[i] > 200000 || nextPos[i]<0)  continue;
            if(visited[nextPos[i]]) continue;
            visited[nextPos[i]] = true;
            q.push({nextPos[i], time+1});
        }
    }
}