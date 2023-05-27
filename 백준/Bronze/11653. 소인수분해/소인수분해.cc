#include <iostream>
#include <vector>

using namespace std;

int n;
bool IsNotPrime[10000001];
vector<int> primeNums;

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n;
    if(n==1)    return 0;
    IsNotPrime[1] = true;
    for(int i=2; i*i<=10000000; i++){
        for(int j=2; i*j<=10000000; j++){
            if(IsNotPrime[i*j])    continue;
            IsNotPrime[i*j] = true;
        }
    }
    for(int i=1; i<=10000000; i++){
        if(!IsNotPrime[i])  primeNums.push_back(i);
    }
    
    int idx=0;
    while(n!=1){
        if(n % primeNums[idx])  idx++;
        else{
            cout<<primeNums[idx]<<endl;
            n /= primeNums[idx];
        }
    }
}