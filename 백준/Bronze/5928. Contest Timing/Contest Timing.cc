#include <iostream>

using namespace std;

int d,h,m;

int main()
{
    cin>>d>>h>>m;

    int end = d*24*60 + h*60 + m;
    int start = 11*24*60 + 11*60 + 11;

    int spentTime = end - start;
    if(spentTime < 0)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<spentTime<<endl;
}