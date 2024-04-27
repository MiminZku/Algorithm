#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int xa,xb,xc, la,lb,lc;
    cin>>xa>>xb>>xc>>la>>lb>>lc;

    int mx = xa*3 + xb*20 + xc*120;
    int ml = la*3 + lb*20 + lc*120;
    if(mx > ml)         cout<<"Max\n";
    else if(mx < ml)    cout<<"Mel\n";
    else                cout<<"Draw\n";
}