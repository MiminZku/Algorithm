#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;

    int temp = n % 8;
    if (temp == 1)                  cout << 1 << endl;
    else if(temp == 2 || temp == 0) cout << 2 << endl;
    else if(temp == 3 || temp == 7) cout << 3 << endl;
    else if(temp == 4 || temp == 6) cout << 4 << endl;
    else                            cout << 5 << endl;
}