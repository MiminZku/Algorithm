#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b==0)    return a;
    return GCD(b, a%b);
}

int main(){
    int  a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    int ra = a1*b2 + a2*b1;
    int rb = b1*b2;
    int gcd = GCD(ra, rb);
    ra /= gcd;
    rb /= gcd;
    cout<<ra<<' '<<rb<<'\n';
}