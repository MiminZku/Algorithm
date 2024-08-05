#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    float actualDef = a * (100 - b) / 100.f;
    if(actualDef >= 100)    cout<<0<<endl;
    else                    cout<<1<<endl;
}