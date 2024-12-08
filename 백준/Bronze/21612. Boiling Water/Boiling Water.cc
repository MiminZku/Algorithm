#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    
    int p = 5 * n - 400;
    cout << p << endl;
    if(p < 100)
    {
        cout << 1 << endl;
    }
    else if(p > 100)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}