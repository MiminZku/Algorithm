#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    int a, b;
    cin>>a>>b;
    if(a <= n && n <= b)
    {
        cout << n << endl;
    }
    else
    {
        if (n < a)
        {
            cout << a << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
}