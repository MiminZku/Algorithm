#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int mat[1001][1001];
bool visited[1001][1001][11];
int n,m,k;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int BFS(){
    queue<vector<int>> q;
    q.push({1,1,1,0,1});  // row, col, 이동한 거리(시작칸 포함), 벽 부순 횟수, 낮인지 여부
    visited[1][1][0] = true;

    while(!q.empty()){
        vector<int> cur = q.front();
        q.pop();
        int curY = cur[0];
        int curX = cur[1];
        int dist = cur[2];
        int crush = cur[3];
        bool isDay = cur[4];

        if(curY == n && curX == m){
            return dist;
        }
        
        if(!isDay)  q.push({curY, curX, dist+1, crush, !isDay});
        for(int i=0; i<4; i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            int nc = crush;
            if(ny<1 || nx<1 || ny>n || nx>m)    continue;
            if(mat[ny][nx]) // 벽일때
            {
                if(!isDay)  continue;
                if(nc == k) continue;
                nc++;
                if(visited[ny][nx][nc]) continue;
                visited[ny][nx][nc] = true;
                q.push({ny, nx, dist+1, nc, !isDay});
            }
            else
            {
                if(visited[ny][nx][nc]) continue;
                visited[ny][nx][nc] = true;
                q.push({ny, nx, dist+1, nc, !isDay});
            }
        }
    }
    return -1;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char ch;
            cin>>ch;
            mat[i][j] = ch - '0';
        }
    }
    cout<<BFS()<<endl;
}