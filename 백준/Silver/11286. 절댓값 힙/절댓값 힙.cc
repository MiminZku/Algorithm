#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int n,i;

struct cmp{
    bool operator()(int n1, int n2){
        if(abs(n1) > abs(n2))   return true;
        else if(abs(n1) == abs(n2)){
            if(n1>n2)   return true;
            else        return false;
        }
        return false;
    }
};

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    priority_queue<int,vector<int>,cmp>   pq;
    while(n--){
        cin>>i;
        if(i){
            pq.push(i);
        }
        else{
            if(pq.empty()){
                cout<<"0\n";
                continue;
            }
            cout<<pq.top()<<'\n';
            pq.pop();
        }
    }
}