#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> deq;
    for(int i=1; i<=n; i++) deq.push_front(i);

    while(deq.size()>1){
        deq.pop_back();

        deq.push_front(deq.back());
        deq.pop_back();
    }
    cout<<deq.front()<<endl;
}