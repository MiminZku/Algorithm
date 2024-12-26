#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;

    for(int i=1; i<=n; ++i)
    {
        cout<<i<<' ';
        if(i % 6 == 0)
        {
            cout<<"Go! ";
        }
        else if(i == n)
        {
            cout<<"Go!";
        }
    }
    cout<<endl;
}