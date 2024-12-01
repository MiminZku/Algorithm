#include <iostream>
using namespace std;

int s, f;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>s>>f;

    if(s <= f)
    {
        cout<<"high speed rail\n";
    }
    else
    {
        cout<<"flight\n";
    }
}