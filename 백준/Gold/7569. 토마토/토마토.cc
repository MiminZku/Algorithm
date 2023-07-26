#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,pair<int,int>> Pos;
int m,n,h;
Pos nav[6] = {{1,{0,0}},{-1,{0,0}},{0,{0,1}}, {0,{0,-1}}, {0,{1,0}}, {0,{-1,0}}};

Pos operator + (const Pos & p1, const Pos & p2){
    return {p1.first+p2.first,
    {p1.second.first+p2.second.first, p1.second.second+p2.second.second}};
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>m>>n>>h;
    int mat[h][n][m];
    queue<pair<Pos,int>> q;
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[k][i][j];
                if(mat[k][i][j]==1)   q.push({{k,{i,j}},0});
            }
        }
    }
    
    int res = 0;
    while(!q.empty()){
        Pos cur = q.front().first;
        int count = q.front().second;
        q.pop();

        for(Pos d : nav){
            Pos nPos = d + cur;
            if(nPos.first < 0 || nPos.second.first < 0 || nPos.second.second<0
                || nPos.first >= h || nPos.second.first >= n || nPos.second.second >= m)   continue;
            int nav_val = mat[nPos.first][nPos.second.first][nPos.second.second];
            if(nav_val != 0) continue;
            mat[nPos.first][nPos.second.first][nPos.second.second] = 1;
            q.push({nPos,count+1});
            res = count+1;
        }
    }
    for(int k=0; k<h; k++){
        for (int i = 0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(mat[k][i][j]==0){
                    res = -1;
                }
            }
        }
    }
    cout<<res<<endl;
}