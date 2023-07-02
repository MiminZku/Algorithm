#include <iostream>

using namespace std;

int r,c,t;
int lab[50][50];
int airCleanerPos[2];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

void Diffuse(){
    int temp[50][50] = {};
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int dust = lab[i][j];
            if(dust<=0)    continue;

            for(int k=0; k<4; k++){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(ny<0 || nx<0 || ny>=r || nx>=c)  continue;
                if(lab[ny][nx]<0)   continue;
                temp[ny][nx] += lab[i][j]/5;
                temp[i][j] -= lab[i][j]/5;
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            lab[i][j] += temp[i][j];
        }
    }
}
void AirCleaner(){
    for(int i=airCleanerPos[0]; i>0; i--)   
        lab[i][0] = lab[i-1][0];
    for(int j=0; j<c-1; j++)
        lab[0][j] = lab[0][j+1];
    for(int i=0; i<airCleanerPos[0]; i++)
        lab[i][c-1] = lab[i+1][c-1];
    lab[airCleanerPos[0]][0] = 0;
    for(int j=c-1; j>0; j--)
        lab[airCleanerPos[0]][j] = lab[airCleanerPos[0]][j-1];
    
    for(int i=airCleanerPos[1]; i<r-1; i++)   
        lab[i][0] = lab[i+1][0];
    for(int j=0; j<c-1; j++)
        lab[r-1][j] = lab[r-1][j+1];
    for(int i=r-1; i>airCleanerPos[1]; i--)
        lab[i][c-1] = lab[i-1][c-1];
    lab[airCleanerPos[1]][0] = 0;
    for(int j=c-1; j>0; j--)
        lab[airCleanerPos[1]][j] = lab[airCleanerPos[1]][j-1];
    
    lab[airCleanerPos[0]][0] = -1;
    lab[airCleanerPos[1]][0] = -1;
}
int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>r>>c>>t;
    int idx=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>lab[i][j];
            if(lab[i][j]==-1)   airCleanerPos[idx++]=i;
        }
    }
    while(t--){
        Diffuse();
        AirCleaner();
    }
    int res = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(lab[i][j]>0) res += lab[i][j];
    cout<<res<<'\n';
}