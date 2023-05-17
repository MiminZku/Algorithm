#include <iostream>

using namespace std;

long long GCD(long long a, long long b){
    if(a%b==0)  return b;
    return GCD(b, a%b);
}

long long LCM(long long a, long long b){
    return a*b/GCD(a,b);
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    long long a,b;
    cin>>a>>b;
    long long lcm = LCM(a,b);
    cout<<lcm<<'\n';

}