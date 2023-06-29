#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<vector<int>> lab;
int res;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int GetSafeSpaceNum(){
    queue<pair<int,int>> q;
    int visited[8][8] = {};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(lab[i][j]==2){
                q.push({i,j});
                visited[i][j] = 1;
            }
            else if(lab[i][j])  visited[i][j] = 1;
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j])   continue;
            cnt++;
        }
    }
    return cnt;
}
void Solve(int wallCnt, int startIdx){
    if(wallCnt==3){
        res = max(res, GetSafeSpaceNum());
    }
    else{
        for(int i=startIdx+1; i<n*m; i++){
            int y = i/m;
            int x = i%m;
            if(lab[y][x])    continue;
            lab[y][x] = 1;
            Solve(wallCnt+1, i);
            lab[y][x] = 0;
        }
    }
}
int main(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin>>n>>m;
    int k;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<m; j++){
            cin>>k;
            temp.push_back(k);
        }
        lab.push_back(temp);
    }
    Solve(0,-1);
    cout<<res<<endl;
}