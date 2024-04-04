#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int i;
    cin>>i;
    if(i%10 == i/10)    cout<<1<<endl;
    else                cout<<0<<endl;
}