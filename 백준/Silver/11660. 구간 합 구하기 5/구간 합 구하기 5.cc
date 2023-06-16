#include <iostream>

using namespace std;

int n,m;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>m;
    long long mat[n][n];
    
    cin>>mat[0][0];
    for(int j=1; j<n; j++){
        cin>>mat[0][j];
        mat[0][j] += mat[0][j-1];
    }
    for(int i=1; i<n; i++){
        cin>>mat[i][0];
        mat[i][0] += mat[i-1][0];
        for(int j=1; j<n; j++){
            cin>>mat[i][j];
            mat[i][j] += mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
        }
    }

    while(m--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;   c1--;
        r2--;   c2--;
        
        long long result = mat[r2][c2];
        if(r1)  result -= mat[r1-1][c2];
        if(c1)  result -= mat[r2][c1-1];
        if(r1 && c1)    result += mat[r1-1][c1-1];
        
        cout<<result<<'\n';
    }
}