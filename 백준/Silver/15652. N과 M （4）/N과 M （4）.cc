#include <iostream>

using namespace std;

int n,m;
int path[8];

void Recur(int level, int start){
    if(level == m){
        for(int i: path){
            if(i)   cout<<i<<' ';
            else{
                cout<<'\n';
                break;
            }
        }
        return;
    }
    for(int i=start; i<=n; i++){
        path[level] = i;
        Recur(level+1, i);
    }
}

int main(){
    cin>>n>>m;
    Recur(0, 1);
}