#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int sum = 0;
    int k;
    while(n--)
    {
        cin>>k;
        sum += k;
    }
    if(sum > 0)         cout<<"Right\n";
    else if(sum < 0)    cout<<"Left\n";
    else                cout<<"Stay\n";
}