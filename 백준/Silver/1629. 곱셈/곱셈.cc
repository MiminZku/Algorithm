#include <iostream>

using namespace std;

long long Solve(long long& a, long long b, long long& c){
    if(b==1) return a % c;
    
    long long temp = Solve(a, b/2, c);
    // cout<<temp<<endl;
    if(b%2) return temp % c * temp % c * a % c;
    else    return temp % c * temp % c % c;
}

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<Solve(a,b,c)<<endl;
}