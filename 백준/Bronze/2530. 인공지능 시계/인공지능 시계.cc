#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int h,m,s,time;
    cin>>h>>m>>s>>time;

    s += time % 60;
    if(s >= 60)
    {
        s -= 60;
        m += 1;
    }
    m += time / 60;
    while(m >= 60)
    {
        m -= 60;
        h += 1;
    }
    h %= 24;

    cout<<h<<' '<<m<<' '<<s<<endl;
}