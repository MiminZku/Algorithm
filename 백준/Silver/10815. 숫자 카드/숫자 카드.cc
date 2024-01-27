#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
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
    for(int i=0; i<m; i++){
        int k;
        cin>>k;
        if(sangn.find(k) == sangn.end()){
            cout<<"0 ";
        }else{
            cout<<"1 ";
        }
    }
    cout<<endl;
}