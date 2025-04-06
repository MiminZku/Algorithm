#include <iostream>

using namespace std;

int t;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> t;
    cin.ignore();
    string a, b;
    while(t--)
    {
        cin >> a >> b;
        if(a.compare(b))
        {
            cout << "ERROR\n";
        }
        else
        {
            cout << "OK\n";
        }
    }
}