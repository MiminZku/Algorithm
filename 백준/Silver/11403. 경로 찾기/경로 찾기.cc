#include <iostream>
#include <queue>

using namespace std;

int n;
int mat[100][100];
bool canVisit[100][100];

void VisitFrom(int src){
    int visited[n]={};
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(!mat[cur][i])    continue;
            if(visited[i]) continue;
            visited[i] = true;
            canVisit[src][i] = true;
            q.push(i);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            if(mat[i][j])
                canVisit[i][j] = true;
        }
    }

    for(int i=0; i<n; i++){
        VisitFrom(i);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(canVisit[i][j])  cout<<"1 ";
            else                cout<<"0 ";
        }cout<<'\n';
    }
}