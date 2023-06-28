#include <iostream>

using namespace std;

int isPrime[1000001];

int Solve(int n){
    int cnt=0;
    for(int i=2; i<=n/2; i++){
        if(!isPrime[i]) continue;
        int left = n-i;
        if(isPrime[left])  cnt++;
    }
    return cnt;
}

int main(){
    for(int i=2; i<1000001; i++)    isPrime[i] = true;
    for(int i=2; i*i <= 1000000; i++){
        if(!isPrime[i]) continue;
        for(int j=i*i; j <= 1000000; j+=i){
            isPrime[j] = false;
        }
    }
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<Solve(n)<<'\n';
    }
}