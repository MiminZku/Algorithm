#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Pos;

int n,m;
Pos startPos;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    char mat[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j]=='I'){
                startPos.first = i;
                startPos.second = j;
            }
        }
    }

    queue<Pos> q;
    q.push(startPos);
    bool visited[600][600] = {};
    visited[startPos.first][startPos.second] = true;
    int cnt = 0;
    while(!q.empty()){
        Pos curPos = q.front();
        q.pop();
        if(mat[curPos.first][curPos.second] == 'P') cnt++;
        int dy[4] = {0,0,-1,1};
        int dx[4] = {-1,1,0,0};
        for(int i=0; i<4; i++){
            int ny = dy[i] + curPos.first;
            int nx = dx[i] + curPos.second;
            if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
            if(mat[ny][nx]=='X')    continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push(make_pair(ny,nx));
        }
    }
    if(cnt) cout<<cnt<<endl;
    else    cout<<"TT\n";
}