#include <iostream>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        int k;
        cin>>k;
        for(int i=0; i<k; ++i)
        {
            cout<<'=';
        }cout<<'\n';
    }
}