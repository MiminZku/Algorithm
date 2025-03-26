#include <iostream>

using namespace std;

long long a,b,c;

long long Mul(long long n, long long m)
{
    if(m==0)    return 1;
    if(m==1)    return a % c;
    
    long long ret = Mul(n, m/2);
    ret = (ret % c) * (ret % c) % c;
    if(m%2) 
    {
        ret *= (a % c);
    }
    
    return ret %= c;
}

int main()
{
    cin>>a>>b>>c;
    cout<<Mul(a,b)<<endl;
}