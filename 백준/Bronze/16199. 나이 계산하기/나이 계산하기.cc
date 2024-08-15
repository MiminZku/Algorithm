#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio;

    int y, m, d;
    cin>>y>>m>>d;

    int ty, tm, td;
    cin>>ty>>tm>>td;

    int temp = ty - y;
    if(tm < m)  --temp;
    else if(tm == m)
    {
        if(td < d) --temp;
    }
    if(temp < 0) temp = 0;
    cout<<temp<<endl;
    cout<<ty - y + 1 << endl;
    cout<<ty - y <<endl;
}