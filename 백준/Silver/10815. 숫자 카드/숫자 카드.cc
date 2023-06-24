#include <iostream>
#include <unordered_set>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

int main(){
    fastio;
    unordered_set<int> sangn;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        sangn.insert(k);
    }
    int m;
    cin>>m;
    int res[m];
    for(int i=0; i<m; i++){
        int k;
        cin>>k;
        if(sangn.find(k) == sangn.end()){
            res[i] = 0;
        }else{
            res[i] = 1;
        }
    }
    for(int i=0; i<m; i++){
        cout<<res[i]<<' ';
    }
    cout<<'\n';
}