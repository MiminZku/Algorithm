#include <iostream>

using namespace std;

int t;

int GCD(int m, int n){
    if(n==0)    return m;
    return GCD(n, m%n);
}

int Year(int m, int n, int x, int y){
    int gcd = GCD(m,n);
    for(int i=0; i<n/gcd; i++){
        if((m*i+x-y)%n) continue;
        return m*i+x;
    }
    return -1;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        cout<<Year(m,n,x,y)<<'\n';
    }
}