#include <iostream>

using namespace std;

long long n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n*n<<'\n';
    }
}