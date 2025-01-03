#include <iostream>

using namespace std;

long long a, b;

int main()
{
    cin>>a>>b;
    long long res;
    if(a % 2 == 0 || b % 2 == 0)
    {
        res = 0;
    }
    else
    {
        res = min(a, b);
    }

    cout<<res<<endl;
}