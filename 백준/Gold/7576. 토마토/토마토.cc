#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> Idx;

int mat[1000][1000];
int n,m;
int day;
Idx navers[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
queue<pair<Idx,int>> q;

void BFS(){
    while(!q.empty()){
        Idx cur = q.front().first;
        int d = q.front().second;
        day = d;
        q.pop();

        for(Idx naver : navers){
            int ny = cur.first + naver.first;
            int nx = cur.second + naver.second;
            if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
            if(mat[ny][nx]) continue;
            mat[ny][nx] = 1;
            q.push({{ny,nx},d+1});
        }
    }
}

bool Check(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0)    return false;
        }
    }
    return true;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j]==1)    q.push({{i,j},day});
        }
    }
    BFS();
    if(Check()) cout<<day<<endl;
    else        cout<<-1<<endl;
}