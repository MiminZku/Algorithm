#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    if(n == 2006)
    {
        cout << "PetrSU, ITMO";
    }
    else if(n == 1996 || n == 1997 || n == 2000 || n == 2007 || n == 2008 ||
            n == 2013 || n == 2018)
    {
        cout << "SPbSU";
    }
    else
    {
        cout << "ITMO";
    }
}