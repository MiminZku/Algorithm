#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

void Paint(vector<vector<int>>& mat, int r, int c, int color){
    mat[r][c] = color;
    
    for(int i=0; i<4; i++){
        int ny = dy[i] + r;
        int nx = dx[i] + c;
        if(ny < 0 || nx < 0 || ny >= mat.size() || nx >= mat[0].size()) continue;
        if(mat[ny][nx] < 0) 
            Paint(mat, ny, nx, color);
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        int m,n,k;
        cin>>m>>n>>k;
        
        vector<vector<int>> mat;
        mat.resize(n);
        for(int i=0; i<n; i++)  mat[i].resize(m);

        while(k--){
            int x,y;
            cin>>x>>y;
            mat[y][x] = -1;
        }

        int color = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] < 0)   Paint(mat, i, j, ++color);
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<mat[i][j]<<' ';
        //     }cout<<endl;
        // }
        cout<<color<<'\n';
    }
}