#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>a>>b;
    for(int i=-1000; i<=1000; ++i)
    {
        if(i*i + i*a*2 + b == 0)
        {
            cout<<i<<' ';
        }
    }
    cout<<endl;
}