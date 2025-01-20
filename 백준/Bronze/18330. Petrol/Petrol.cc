#include <iostream>

using namespace std;

int n;
int k;

int main()
{
    cin >> n >> k;
    int res = 0;
    if(n <= 60)
    {
        res = n * 1500;
    }
    else
    {
        if(n - 60 - k <= 0)
        {
            res = n * 1500;
        }
        else
        {
            res = (60 + k) * 1500 + (n - 60 - k) * 3000;
        }
    }

    cout << res << endl;
}