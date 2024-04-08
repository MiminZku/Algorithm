#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int i = 8;
    while(i--)
    {
        int k;
        cin>>k;
        if(!(k==1 || k==0))
        {
            cout<<"F\n";
            return 0;
        }
    }
    cout<<"S\n";
}