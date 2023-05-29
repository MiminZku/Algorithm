#include <iostream>

using namespace std;

long long Func(long long n){
    return n*(n-1)/2;
}

int main(){
    long long n;
    cin>>n;
    cout<<Func(n)<<"\n2\n";
}