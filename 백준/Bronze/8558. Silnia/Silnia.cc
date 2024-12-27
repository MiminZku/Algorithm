#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    int res = 1;
    for(int i=2; i<=n; ++i)
    {
        res *= i;
        res %= 10;
    }
    cout<<res<<endl;
}