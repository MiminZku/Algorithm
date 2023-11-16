#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        if(str.size() >=6 && str.size() <= 9)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
}