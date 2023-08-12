#include <iostream>
#include <queue>

using namespace std;

struct Pos{
    int row;
    int col;
};
queue<pair<Pos,int>> playerQ;
queue<Pos> fireQ;

int r,c;
char mat[1002][1002];
bool visited[1002][1002];
bool fire[1002][1002];

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int BFS(){
    int prevTime = -1;
    while(!playerQ.empty()){
        Pos curPos = playerQ.front().first;
        int time = playerQ.front().second;
        playerQ.pop();

        if(time != prevTime){
            prevTime = time;

            vector<Pos> firePos;
            while(!fireQ.empty()){
                firePos.push_back(fireQ.front());
                fireQ.pop();
            }
            for(Pos& p : firePos){
                for(int i=0; i<4; i++){
                    int ny = p.row + dy[i];
                    int nx = p.col + dx[i];
                    if(ny<1 || nx<1 || ny>r || nx>c)    continue;
                    if(mat[ny][nx] == '#')  continue;
                    if(fire[ny][nx])  continue;
                    fire[ny][nx] = true;
                    fireQ.push({ny,nx});
                }
            }
        }

        if(mat[curPos.row][curPos.col] == 'E')  return time;

        for(int i=0; i<4; i++){
            int ny = curPos.row + dy[i];
            int nx = curPos.col + dx[i];
            if(ny<0 || nx<0 || ny>r+1 || nx>c+1)    continue;
            if(mat[ny][nx] == '#')  continue;
            if(fire[ny][nx])    continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            playerQ.push({{ny,nx},time+1});
        }
    }
    return -1;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>r>>c;
    for(int i=0; i<=r+1; i++){
        mat[i][0] = 'E';
        mat[i][c+1] = 'E';
    }
    for(int j=0; j<=c+1; j++){
        mat[0][j] = 'E';
        mat[r+1][j] = 'E';
    }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'J'){
                playerQ.push({{i,j}, 0});
                visited[i][j] = true;
            }
            else if(mat[i][j] == 'F'){
                fireQ.push({i,j});
                fire[i][j] = true;
            }
        }
    }
    
    int result = BFS();
    if(result == -1)    cout<<"IMPOSSIBLE\n";
    else                cout<<result<<endl;
}