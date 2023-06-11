#include <iostream>
#include <algorithm>
#include <queue>

#define D 0
#define S 1
#define L 2
#define R 3

using namespace std;

int t;
bool visited[10000];
int parent[10000];
int command[10000];

int DSLR(int command, int num){
    int result;
    if(command == D)    result = (num*2)%10000;
    else if(command == S){
        result = num-1;
        if(result<0)   result = 9999;
    }
    else if(command == L)   result = (num%1000)*10 + num/1000;
    else if(command == R)   result = (num%10)*1000 + num/10;
    return result;
}

void Solve(int a, int b, vector<int>& result){
    fill_n(parent,10000,-1);
    fill_n(command,10000,-1);
    fill_n(visited,10000,false);
    queue<pair<int,pair<int,int>>> q;
    q.push({a,{-1,-1}});
    visited[a] = true;

    while(!q.empty()){
        int cur = q.front().first;
        q.pop();

        if(cur==b){
            while(parent[cur]>=0){
                result.push_back(command[cur]);
                cur = parent[cur];
            }
            reverse(result.begin(),result.end());
            return;
        }

        for(int i=0; i<4; i++){
            int next = DSLR(i, cur);
            if(visited[next])   continue;
            visited[next] = true;
            parent[next] = cur;
            command[next] = i;
            q.push({next,{cur,i}});
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        vector<int> result;
        Solve(a, b, result);
        for(int i: result){
            if(i==D)        cout<<'D';
            else if(i==S)   cout<<'S';
            else if(i==L)   cout<<'L';
            else if(i==R)   cout<<'R';
        }
        cout<<'\n';
    }
}