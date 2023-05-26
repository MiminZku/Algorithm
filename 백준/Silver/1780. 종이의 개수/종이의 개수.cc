#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> mat;
int res[3];

bool IsOneNum(int r1, int c1, int r2, int c2){
    int first = mat[r1][c1];
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            if(mat[i][j]!=first)    return false;
        }
    }
    return true;
}

void Solve(int r1, int c1, int r2, int c2){
    if(IsOneNum(r1, c1, r2, c2)){
        res[mat[r1][c1]+1]++;
    }
    else{
        int len = r2-r1+1;
        len /= 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Solve(r1+len*i, c1+len*j, r1+len*(i+1)-1, c1+len*(j+1)-1);
            }
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            temp.push_back(k);
        }
        mat.push_back(temp);
    }

    Solve(0,0,n-1,n-1);

    for(int i=0; i<3; i++)  cout<<res[i]<<'\n';
}   