#include <iostream>

using namespace std;

string arr[] = 
{
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN",
};

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int m = x - 1;
    int d = y - 1;

    for(int i=1; i<x; ++i)
    {
        switch(i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                d += 31;
                break;

            case 2:
                d += 28;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                d += 30;
                break;
        }
    }

    cout << arr[d % 7] << endl;
}