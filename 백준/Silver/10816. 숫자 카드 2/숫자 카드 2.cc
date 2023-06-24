#include <iostream>
#include <unordered_map>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

int main(){
    fastio;
    unordered_map<int, int> sangn;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        if(sangn.find(k) == sangn.end())    sangn.insert({k,1});
        else    sangn[k] += 1;
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
            res[i] = sangn[k];
        }
    }
    for(int i=0; i<m; i++){
        cout<<res[i]<<' ';
    }
    cout<<'\n';
}