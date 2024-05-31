#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int a, b;
    while (true)
    {
        cin>>a>>b;
        if(0 == a && 0 == b)    break;
        cout<<a+b<<'\n';
    }
}