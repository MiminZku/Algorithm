#include <iostream>

using namespace std;

int s, a, b;

int main()
{
    cin >> s >> a >> b;

    if(a >= s)
    {
        cout << 250 << endl;
        return 0;
    }
    
    int left = s - a;
    int add;
    if(left % b == 0)
    {
        add = left / b;
    }
    else
    {
        add = left / b + 1;
    }
    cout << 250 + 100 * add << endl;
}