#include <iostream>

using namespace std;

int n,m;
int path[8];

void Recursive(int level,int start){
    if(level==m){
        for(int i=0; i<m; i++)
            cout<<path[i]<<' ';
        cout<<endl;
        return;
    }
    else{
        for(int i=start; i<=n; i++){
            path[level]=i;
            Recursive(level+1,i+1);
        }
    }
}

int main(){
    cin>>n>>m;
    Recursive(0,1);
}