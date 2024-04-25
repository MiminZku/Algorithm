#include <iostream>

using namespace std;

int a, b, n, w;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>a>>b>>n>>w;
    
    int sheep = -1;
    int cnt = 0;

    for (int i=1; i<n; ++i)
    {
        if(a*i + b*(n-i) == w)
        {
            sheep = i;
            ++cnt;
        }
    }
    
    if(1 == cnt)    cout<<sheep<<' '<<n-sheep<<endl;
    else            cout<<"-1\n";
}