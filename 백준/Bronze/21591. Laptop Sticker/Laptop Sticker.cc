#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a > c + 1 && b > d + 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}