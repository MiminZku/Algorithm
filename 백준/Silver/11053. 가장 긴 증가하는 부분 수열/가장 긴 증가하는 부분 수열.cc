#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int LIS_table[1001][1001];

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    arr.push_back(0);
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }

    for(int i=n; i>=0; i--){
        for(int j=n; j>0; j--){
            if(j==i){
                LIS_table[i][j] = 1;
                continue;
            }
            if(arr[i] < arr[j])
                LIS_table[i][j] = max(LIS_table[i][j+1], 1+LIS_table[j][j+1]);
            else
                LIS_table[i][j] = LIS_table[i][j+1];
        }
    }
    
    cout<<LIS_table[0][1]<<endl;
}