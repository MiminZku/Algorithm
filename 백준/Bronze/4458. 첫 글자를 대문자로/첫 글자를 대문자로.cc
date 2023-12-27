#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    while(n--)
    {
        string str;
        getline(cin, str);

        if(str[0] >= 97) str[0] -= 32;
        cout<<str<<'\n';
    }
}