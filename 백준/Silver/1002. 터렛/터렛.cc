#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    int x1, y1, r1, x2, y2, r2;
    while(t--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int width = abs(x1 - x2);
        int height = abs(y1 - y2);

        int distSquared = width * width + height * height;
        int r = r1 + r2;
        r *= r;
        if(distSquared == 0 && r1 == r2)
        {
            cout << "-1\n";
        }
        else if(r > distSquared && abs(r1-r2)*abs(r1-r2) < distSquared)
        {
            cout << "2\n";
        }
        else if(r == distSquared || abs(r1-r2)*abs(r1-r2) == distSquared)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}