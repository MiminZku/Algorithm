#include <iostream>
#include <deque>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;

    deque<pair<int,int>> deq;   // index, value
    int k;
    for(int i=0; i<n; i++){
        cin>>k;
        
        while(!deq.empty() && deq.back().second > k) deq.pop_back();
    
        deq.push_back({i,k});

        while(deq.front().first <= i-l) deq.pop_front();

        cout<<deq.front().second<<' ';
    }
    cout<<'\n';
}