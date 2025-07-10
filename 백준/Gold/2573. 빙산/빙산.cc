#include <iostream>

using namespace std;

int n,m;
int mat[300][300];
bool visited[300][300];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void Melt()
{
    int temp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!mat[i][j])  continue;
            int waterCnt = 0;
            for(int k=0; k<4; k++){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
                if(mat[ny][nx]!=0)  continue;
                waterCnt++;
            }
            temp[i][j] = waterCnt;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!mat[i][j])  continue;
            mat[i][j] -= temp[i][j];
            if(mat[i][j]<0) mat[i][j] = 0;
        }
    }
}

void DFS(int row, int col){
    visited[row][col] = true;
    for(int i=0; i<4; i++){
        int ny = row + dy[i];
        int nx = col + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=m)  continue;
        if(!mat[ny][nx])    continue;
        if(visited[ny][nx]) continue;
        DFS(ny, nx);
    }
}

int Separated(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!mat[i][j])  continue;
            if(visited[i][j])   continue;
            cnt++;
            DFS(i,j);
        }
    }
    return cnt;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    int year = 0;
    while(true){
        year++;
        Melt();
        int iceberg = Separated();
        if(iceberg > 1){
            cout<<year<<endl;
            break;
        }
        else if(iceberg == 0){
            cout<<0<<endl;
            break;
        }
    }
}