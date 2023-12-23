#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1; i<=n; i++)
    {
        string str;
        getline(cin, str);
        for(char ch : str)
        {
            if(ch < 97)
            {
                cout<<char(ch+32);
            }
            else
            {
                cout<<ch;
            }
        }
        cout<<'\n';
    }
}