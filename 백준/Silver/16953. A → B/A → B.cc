#include <iostream>
#include <queue>

using namespace std;

int a,b;

int Oper(int n, int type){
    if(type==1)         return n/10;
    else if(type==2)    return n/2;
    return -1;
}

int BFS(){
    queue<pair<int,int>> q;
    q.push({b,0});

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur==a)  return cnt;
        if(cur<1)   break;

        int next;
        if(cur%10 == 1)     next = Oper(cur, 1);
        else if(cur%2==0)   next = Oper(cur, 2);
        else    break;

        q.push({next,cnt+1});
    }
    return -2;
}

int main(){
    cin>>a>>b;
    cout<<BFS()+1<<endl;
}