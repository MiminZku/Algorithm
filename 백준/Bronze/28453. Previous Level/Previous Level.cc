#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int k;
        cin >> k;
        if(k < 250)         cout << "4 ";
        else if(k < 275)    cout << "3 ";
        else if(k < 300)    cout << "2 ";
        else                cout << "1 ";
    }
    cout << endl;
}