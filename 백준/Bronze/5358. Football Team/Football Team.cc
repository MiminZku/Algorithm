#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    string str;
    while(getline(cin, str))
    {
        for(char ch : str)
        {
            if(ch == 'i')       cout<<'e';
            else if(ch == 'I')  cout<<'E';
            else if(ch == 'e')  cout<<'i';
            else if(ch == 'E')  cout<<'I';
            else                cout<<ch;
        }
        cout<<'\n';
    }
}