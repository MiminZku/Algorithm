#include <iostream>

using namespace std;

int GCD(int a, int b){
    int big = a;
    int small = b;
    if(b>a){
        big = b;
        small = a;
    }
    while(small != 0){
        int m = big % small;
        big = small;
        small = m;
    }
    return big;
}
int LCM(int a, int b, int gcd){
    return (a*b/gcd);
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;  cin>>t;
    for(int i=0; i<t; i++){
        int a,b;
        cin>>a>>b;
        int gcd = GCD(a,b);
        int lcm = LCM(a,b,gcd);
        cout<<lcm<<'\n';
    }
}