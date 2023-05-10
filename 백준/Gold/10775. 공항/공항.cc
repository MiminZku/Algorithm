#include <iostream>
#include <vector>

#define fastio cin.tie(nullptr),ios::sync_with_stdio(false)

using namespace std;

int g,p;
vector<int> planeSeq;
int nextGate[100001];

int find(int gi){
    if(gi==nextGate[gi])    return gi;
    else    return nextGate[gi]=find(nextGate[gi]);
}

int main(){
    fastio;
    cin>>g;
    cin>>p;
    for(int i=1; i<=g; i++){
        nextGate[i] = i;
    } 
    for(int i=0; i<p; i++){
        int n;
        cin>>n;
        planeSeq.push_back(n);
    }

    int count = 0;
    for(int gi : planeSeq){
        int i = find(gi);
        if(i==0) break;
        nextGate[i] = nextGate[i-1];
        count++;
    }
    cout<<count<<endl;
}