#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        cout<<k<<' '<<k<<'\n';
    }
}