#include <iostream>
#include <queue>

using namespace std;

int n;
int mat[100][100];
int temp[100][100];
int minHeight = 101, maxHeight;
int result = 1;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void DFS(int r, int c, int color){
    temp[r][c] = color;
    
    for(int i=0; i<4; i++){
        int ny = r + dy[i];
        int nx = c + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>= n) continue;
        if(temp[ny][nx]>=0) continue;
        DFS(ny, nx, color);
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            if(mat[i][j]<minHeight) minHeight = mat[i][j];
            if(mat[i][j]>maxHeight) maxHeight = mat[i][j];
        }
    }

    for(int h=minHeight; h<maxHeight; h++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]>h) temp[i][j] = -1;
                else            temp[i][j] = 0;
            }
        }

        int color = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j]>=0)   continue;
                DFS(i, j, ++color);
            }
        }
        // cout<<h<<' '<<color<<endl;
        result = max(result, color);
    }
    cout<<result<<endl;   
}