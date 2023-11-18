#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int x,y;
    cin>>n;
    cin>>x>>y;
    int result = 0;
    int prevX = x, prevY = y;
    int curX, curY;
    while(--n)
    {
        cin>>curX>>curY;
        result += abs(curX-prevX) + abs(curY-prevY);
        prevX = curX;
        prevY = curY;
    }
    result += abs(prevX-x) + abs(prevY-y);
    cout<<result<<endl;
}