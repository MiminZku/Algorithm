#include <iostream>
#include <queue>

using namespace std;

int mat[100][100];
int n,m;

typedef pair<int,int> Pos;
Pos navers[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int BFS(){
    bool visited[100][100] = {};
    visited[0][0] = true;

    queue<pair<Pos,int>> q;
    q.push({{0,0},1});

    while(!q.empty()){
        Pos curPos = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(curPos.first == n-1 && curPos.second == m-1)    return dist;
        for(Pos naver : navers){
            int ny = naver.first + curPos.first;
            int nx = naver.second + curPos. second;
            if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
            if(!mat[ny][nx])    continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({{ny,nx},dist+1});
        }
    }
    return 0;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        char str[101] = {};
        cin>>str;
        for(int j=0; j<m; j++){
            mat[i][j] = str[j]-'0';
        }        
    }
    cout<<BFS()<<endl;
}