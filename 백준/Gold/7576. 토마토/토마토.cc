#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> Index;
int m,n;

Index operator + (const Index & p1, const Index & p2){
    return {p1.first+p2.first, p1.second+p2.second};
}

int main(){
    scanf("%d %d",&m, &n);
    int mat[n][m];
    vector<Index> start;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==1)   start.push_back({i,j});
        }
    }
    int res = 0;
    Index nav[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    queue<pair<Index,int>> q;
    for(Index i : start){
        q.push({i,0});
    }
    while(!q.empty()){
        Index cur = q.front().first;
        int count = q.front().second;
        q.pop();

        vector<Index> navers;
        for(Index idx : nav){
            Index nav_idx = idx + cur;
            if(nav_idx.first < 0 or nav_idx.second < 0
                or nav_idx.first >= n or nav_idx.second >= m)   continue;
            int nav_val = mat[nav_idx.first][nav_idx.second];
            if(nav_val != 0) continue;
            mat[nav_idx.first][nav_idx.second] = 1;
            q.push({nav_idx,count+1});
            res = count+1;
        }
    }
    for (int i = 0; i<n ; i++){
        for(int j=0; j<m; j++){
            // printf("%2d ",mat[i][j]);
            if(mat[i][j]==0){
                res = -1;
            }
        }
        // printf("\n");
    }
    printf("%d\n",res);
}