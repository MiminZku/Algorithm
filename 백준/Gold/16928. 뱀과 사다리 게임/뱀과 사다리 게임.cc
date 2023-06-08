#include <iostream>
#include <queue>

using namespace std;

int n,m;
int snake[101];
int ladder[101];
bool visited[101];

int main(){
    cin>>n>>m;
    int u,v;
    while(n--){
        cin>>u>>v;
        ladder[u] = v;
    }
    while(m--){
        cin>>u>>v;
        snake[u] = v;
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        
        if(ladder[cur]){
            q.front().first = ladder[cur];
            visited[ladder[cur]] = true;
            continue;
        }
        else if(snake[cur]){
            q.front().first = snake[cur];
            visited[snake[cur]] = true;
            continue;
        }
        q.pop();

        if(cur==100){
            cout<<cnt<<endl;
            break;
        }
        for(int i=1; i<=6; i++){
            int next = cur+i;
            if(next>100)        continue;
            if(visited[next])   continue;
            visited[next] = true;
            q.push({next, cnt+1});
        }
    }
}