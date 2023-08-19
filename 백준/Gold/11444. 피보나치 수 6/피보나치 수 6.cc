#include <iostream>
#include <map>

using namespace std;

long long n;
map<int, int> fibo;

long long F(long long _n)
{
    if(_n==0)   return 0;
    if(_n==1)   return 1;
    if(_n==2)   return 1;
    if(fibo.find(_n) != fibo.end()) return fibo[_n];
    if(_n%2)
    {
        fibo[_n] = ((F((_n+1)/2)*F((_n+1)/2))%1000000007
         + (F((_n-1)/2)*F((_n-1)/2))%1000000007)%1000000007;
    }
    else
    {
        fibo[_n] = (F(_n/2) * (F(_n/2 + 1) + F(_n/2 - 1))%1000000007)%1000000007;
    }
    return fibo[_n];
}

int main()
{
    cin>>n;
    cout<<F(n)<<endl;
}