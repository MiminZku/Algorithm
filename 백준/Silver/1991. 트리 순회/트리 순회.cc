#include <iostream>

using namespace std;

int n;
int_fast64_t child[27][2];

void DFS(const int& type, int node){
    if(node == -1)  return;

    switch( type ){
    case 1:
        cout<<(char)('A'+node);
        DFS(type, child[node][0]);
        DFS(type, child[node][1]);
        break;
    case 2:
        DFS(type, child[node][0]);
        cout<<(char)('A'+node);
        DFS(type, child[node][1]);
        break;
    case 3:
        DFS(type, child[node][0]);
        DFS(type, child[node][1]);
        cout<<(char)('A'+node);
        break;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        char p, c1, c2;
        cin>>p>>c1>>c2;
        if(c1!='.') child[p-'A'][0] = c1-'A';
        else        child[p-'A'][0] = -1;
        if(c2!='.') child[p-'A'][1] = c2-'A';
        else        child[p-'A'][1] = -1;
    }
    DFS(1, 0);  cout<<'\n';
    DFS(2, 0);  cout<<'\n';
    DFS(3, 0);  cout<<'\n';
}