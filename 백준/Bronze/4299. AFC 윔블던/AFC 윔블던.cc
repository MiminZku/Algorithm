#include <iostream>

using namespace std;

int s, d;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> s >> d;

    if((s+d)%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int a = (s + d) / 2;
    int b = s - a;

    if(a < 0 || b < 0) cout<<-1<<endl;
    else                cout<<a<<' '<<b<<endl;    
}