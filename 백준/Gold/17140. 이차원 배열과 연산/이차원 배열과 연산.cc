#include <iostream>
#include <vector>
#include <algorithm>

#define fastio cin.tie(nullptr), ios::sync_with_stdio(false);

using namespace std;


void RotateRight(vector<vector<int>>& mat, int& rLen, int& cLen){
    vector<vector<int>> org(mat);
    reverse(org.begin(),org.end());
    mat.clear();
    for(int j=0; j<cLen; j++){
        vector<int> temp;
        for(int i=0; i<rLen; i++){
            temp.push_back(org[i][j]);
        }
        mat.push_back(temp);
    }
    int temp = rLen;
    rLen = cLen;
    cLen = temp;
}
void RotateLeft(vector<vector<int>>& mat, int& rLen, int& cLen){
    vector<vector<int>> org(mat);
    mat.clear();
    for(int j=cLen-1; j>=0; j--){
        vector<int> temp;
        for(int i=0 ; i<rLen ; i++){
            temp.push_back(org[i][j]);
        }
        mat.push_back(temp);
    }
    int temp = rLen;
    rLen = cLen;
    cLen = temp;
}

void SortLine(vector<int>& line){
    int count[101] ={0};
    for(int n : line){
        count[n] += 1;
    }
    
    vector<pair<int,int>> count_list;
    for (int i = 1; i<101 ; i++){
        if(count[i]==0)    continue;
        count_list.push_back({count[i],i});
    }
    sort(count_list.begin(),count_list.end());
    
    line.clear();
    for(pair<int,int> p : count_list){
        line.push_back(p.second);
        if(line.size()==100)    break;
        line.push_back(p.first);
        if(line.size()==100)    break;
    }
}
void SortMat(vector<vector<int>>& mat, int& c_size){
    int max = 0;
    for(vector<int>& row : mat){
        SortLine(row);
        if(row.size() > max) max = row.size();
    }
    for(vector<int>& row : mat){
        while(row.size() < max){
            row.push_back(0);
        }
    }
    c_size = max;
}
int Solve(vector<vector<int>>& mat, int r, int c, int k){
    int r_size = mat.size(); int c_size = mat[0].size();
    for(int time=0; time<=100; time++){
        if(r<=r_size && c<=c_size && mat[r-1][c-1] == k)  return time;
        r_size = mat.size();
        c_size = mat[0].size();

        if(r_size >= c_size){
            SortMat(mat, c_size);
        }
        else{
            RotateLeft(mat, r_size, c_size);
            SortMat(mat, c_size);
            RotateRight(mat, r_size, c_size);
        }
    }
    return -1;
}

int main(){
    int r,c,k;
    cin>>r>>c>>k;
    vector<vector<int>> mat;

    for(int i=0; i<3; i++){
        vector<int> row;
        for(int j=0; j<3; j++){
            int n;
            cin>>n;
            row.push_back(n);
        }
        mat.push_back(row);
    }
    cout<<Solve(mat,r,c,k)<<'\n';
}