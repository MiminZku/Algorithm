#include <iostream>
#include <vector>

using namespace std;

int n,r,q;
vector<int> navers[100001];
int treeSize[100001];

int MakeTree(int curNode, int parent){
    int count = 1;
    for(int& naver : navers[curNode]){
        if(naver==parent)   continue;
        count += MakeTree(naver, curNode);
    }
    return treeSize[curNode] = count;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n>>r>>q;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        navers[a].push_back(b);
        navers[b].push_back(a);
    }
    
    MakeTree(r,0);

    while(q--){
        int k;
        cin>>k;
        cout<<treeSize[k]<<'\n';
    }
}