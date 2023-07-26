#include <iostream>

using namespace std;

int n;
char picture1[100][101];    // 비색약
char picture2[100][101];    // 색약
int cnt1, cnt2;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

void Paint(char picture[100][101], int row, int col){
    char org = picture[row][col];
    picture[row][col] = 0;
    
    for(int i=0; i<4; i++){
        int ny = row + dy[i];
        int nx = col + dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=n)  continue;
        if(picture[ny][nx]!=org)  continue;
        Paint(picture, ny, nx);
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++){
        char str[101];
        cin>>str;
        for(int j=0; j<n; j++){
            picture1[i][j] = str[j];
            if(str[j]=='G') str[j] = 'R';
            picture2[i][j] = str[j];
        }        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(picture1[i][j]){
                Paint(picture1,i,j);
                cnt1++;
            }
            if(picture2[i][j]){
                Paint(picture2,i,j);
                cnt2++;
            }
        }
    }
    cout<<cnt1<<' '<<cnt2<<endl;
}