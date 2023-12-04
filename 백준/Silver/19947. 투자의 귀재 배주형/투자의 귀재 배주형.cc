#include <iostream>

using namespace std;

double mag[] = {1.05, 1.2, 1.35};

int main()
{
    int h,y;
    cin>>h>>y;

    int money[11] = {h, };

    for(int i=1; i<=y; i++)
    {
        int next = money[i-1] * mag[0];
        if(i>=3)
        {
            next = max(next, int(money[i-3] * mag[1]));
        }
        if(i>=5)
        {
            next = max(next, int(money[i-5] * mag[2]));
        }
        money[i] = next;
    }

    cout<<money[y]<<endl;
}