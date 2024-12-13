#include <iostream>

using namespace std;

int a, b, c;

int main()
{
    cin>>a>>b>>c;
    int x = max(b, a - b);
    int y = max(c, a - c);
    cout<<4*x*y<<endl;
}