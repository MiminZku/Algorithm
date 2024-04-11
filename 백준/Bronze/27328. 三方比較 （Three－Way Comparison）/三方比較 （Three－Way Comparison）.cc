#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;

    if(a<b)
    {
        cout<<-1<<'\n';
    }
    else if(a>b)
    {
        cout<<1<<'\n';
    }
    else
    {
        cout<<0<<'\n';
    }
}