#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mat[25][25];
int n;
vector<int> pops;
int cnt;

void Color(int r, int c, int color){
    mat[r][c] = color;
    cnt++;

    int dy[4] = {0,0,-1,1};
    int dx[4] = {1,-1,0,0,};
    for(int i=0; i<4; i++){
        int ny = r+dy[i];
        int nx = c+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=n)  continue;
        if(mat[ny][nx]!=-1) continue;
        Color(ny,nx,color);
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        char str[26] = {};
        cin>>str;
        for(int j=0; j<n; j++){
            int value = str[j]-'0';
            if(value)   mat[i][j] = -1;
            else        mat[i][j] = 0;
        }        
    }
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] != -1)  continue;
            Color(i,j,++k);
            pops.push_back(cnt);
            cnt = 0;
        }
    }
    cout<<k<<endl;
    sort(pops.begin(),pops.end());
    for(int i : pops)   cout<<i<<endl;
}