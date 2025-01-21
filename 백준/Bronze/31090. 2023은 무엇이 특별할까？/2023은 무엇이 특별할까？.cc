#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int year;
        cin >> year;

        int tmp = year % 100;
        year += 1;
        if(year % tmp == 0)
        {
            cout << "Good\n";
        }
        else
        {
            cout << "Bye\n";
        }
    }
}