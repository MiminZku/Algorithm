#include <iostream>

using namespace std;

bool IsPrime(long long n){
    if(n<2) return false;
    for(long long i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

long long Solve(long long n){
    for(long long i=n;;i++){
        if(IsPrime(i)){
            return i;
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<Solve(n)<<'\n';
    }    
}